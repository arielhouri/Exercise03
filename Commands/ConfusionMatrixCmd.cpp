//
// Created by Yonatan Semidubersky on 8/31/2022.
//

#include <fstream>
#include "ConfusionMatrixCmd.hpp"
#include "../Classifier/ClassifierKnn.hpp"
#include <algorithm>
#include "../Classifier/Classifiable.hpp"
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
#include "cstring"

ConfusionMatrixCmd::ConfusionMatrixCmd(ClassificationFiles *files,
                                       ClassifierParameters *newClassParams, DefaultIO *dio) :
        classParams(newClassParams) {
    this->files = files;
    this->description = "display algorithm confusion matrix";
    this->dio = dio;
}

string ConfusionMatrixCmd::getType(const string &line) {
    stringstream str(line);
    string word;
    const char delimiter = ',';
    int amountOfArgs = count(line.begin(), line.end(), delimiter);
    int i = 0;
    // get rid of the fields to get the type
    for (; i < amountOfArgs; i++) {
        getline(str, word, ',');
    }
    getline(str, word, '\n');
    string type = word;
    return type;
}
map<string, int> ConfusionMatrixCmd::mapTypes(string classified){
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string line;
    std::string token = classified.substr(pos, classified.find(delimiter));
    // ---- for storing the types ----
    string type; // real type.
    map<string, int> realTypes; // map of types and num of shows
    map<string, int>::iterator itr; // map iterator
    bool isExist; // is the type exist in map
    // scanning the classified:
    while ((pos = classified.find(delimiter)) != std::string::npos) {
        token = classified.substr(0, classified.find(delimiter));
        classified.erase(0, pos + delimiter.length());
        // windows' fixing ('\r'):
        if (token.find("\r") != std::string::npos){
            line = token.substr(0, token.find("\r"));
            line += "\n";
        }
        else{
            line = token;
        }
        type = getType(line);
        isExist = false;
        // scanning the vector, check if the type exist.
        for (itr = realTypes.begin(); itr != realTypes.end(); itr++) {
            if (itr->first == type) {
                itr->second = itr->second + 1; // another show of the type
                isExist = true;
            }
        }
        if (!isExist) {
            realTypes.insert(pair<string, int>(type, 1)); // add the type
        }
    }
    return realTypes;
}
int ConfusionMatrixCmd::get(const string& key, map<string, int> types){
    int index = 0;
    std::map<std::string, int>::iterator itr;
    for (itr = types.begin(); itr != types.end(); ++itr){
        if (itr->first == key){
            return index;
        }
        index++;
    }
    return -1;
}
void ConfusionMatrixCmd::execute() {
    string classified = this->files->getClassified(); // copy the classified
    if (classified.empty()) {
        this->dio->write("$print$Error!");
        this->dio->read();
        return;
    }
    map<string, int> realTypes = mapTypes(classified);
    // setting the matrix:
    std::vector<std::vector<double> > mat(realTypes.size()); // matrix builder
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string line;
    std::string token = classified.substr(pos, classified.find(delimiter));
    string type;
    map<string, int>::iterator itr;
    for (int i = 0; i < realTypes.size(); i++) {
        mat[i].resize(realTypes.size());
    }
    for (int i = 0; i < realTypes.size(); i++) {
        for (int j = 0; j < realTypes.size(); j++){
            mat[i][j] = 0;
        }
    }
    classified = this->files->getClassified();
    vector<Classifiable> database = ClassifierKnn::setupDatabase(classified); // Creates the database.
    while ((pos = classified.find(delimiter)) != std::string::npos) {
        token = classified.substr(0, classified.find(delimiter));
        classified.erase(0, pos + delimiter.length());
        // windows' fixing ('\r'):
        if (token.find("\r") != std::string::npos){
            line = token.substr(0, token.find("\r"));
            line += "\n";
        }
        else{
            line = token;
        }
        type = getType(line);
        int row = get(type,realTypes);
        Classifiable toClass = ClassifierKnn::stringToClassifiable(&line, true);
        ClassifierKnn classifier(database, toClass, this->classParams->getK()); // Creates its classifier.
        string classType = classifier.classify(*(this->classParams));
        // windows' fixing ('\r'):
        if (classType.find("\r") != std::string::npos){
            classType = classType.substr(0, classType.find("\r"));
        }
        int col = get(classType, realTypes);
        mat[row][col] += 1;
    }
    string matrixPrint = "\t";
    for (itr = realTypes.begin(); itr != realTypes.end(); itr++) {
        matrixPrint += itr->first;
        matrixPrint += "\t";
    }
    matrixPrint += "\n";
    itr = realTypes.begin();
    for (int i = 0; i < realTypes.size(); i++) {
        matrixPrint += itr->first;
        matrixPrint += "\t";
        for (int j = 0; j < realTypes.size(); j++) {
            matrixPrint += to_string((int) (round(100 * ((mat[i][j]) / itr->second)))) + "%\t";
        }
        matrixPrint += "\n";
        ++itr;
    }
    matrixPrint += ("k: " + to_string(this->classParams->getK()) +
                    " metric: " + this->classParams->getMetric());
    this->dio->write("$print$" + matrixPrint);
    this->dio->read();
}
//
// Created by ariel on 8/19/2022.
//

#include <fstream>
#include "ConfusionMatrixCmd.hpp"
#include "Classifier/ClassifierKnn.hpp"
#include <algorithm>
#include "Classifier/Classifiable.hpp"
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
//    std::fstream fin; // Opens the already-classified objects file.ד
//    if (classified.empty()) {
//        this->dio->write("Error!");
//        return;
//    }
//    fin.open(this->classified, std::fstream::in);
//    std::string line;
//    while(getline(fin, line)) { // Loop over all the lines of the already-classified objects file.
//        std::string type = ClassifierKnn::stringToClassifiable(&line).getType();
//        auto it = find(types.begin(), types.end(), type); // Gets a vector of the types
//        if (it == types.end()) {
//            types.push_back(type);
//        }
//    }
//
//    fin.close(); // Closes the results file-stream.
}

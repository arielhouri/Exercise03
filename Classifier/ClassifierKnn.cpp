//
// Created by Yonatan Semidubersky on 21/07/2022.
//
#include <iostream>
#include "ClassifierKnn.hpp"
#include <algorithm>
#include <sstream>
#include <fstream>


using namespace std;
// constructor
ClassifierKnn::ClassifierKnn(vector<Classifiable>& classifiableObjectsVector, Classifiable& toClassifier, int k){
    this->classifiableObjectsVector = classifiableObjectsVector;
    this->toClassifier = toClassifier;
    this->k = k;
}

// classifier by euclidean metric
string ClassifierKnn::classifierEuclidean(){
    int length = (this->classifiableObjectsVector).size();
    vector<ClassifiableAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(ClassifiableAndDistance((this->classifiableObjectsVector)[i],
                                                    (this->toClassifier).euclideanDistance((this->classifiableObjectsVector)[i])));
    }
    return ClassifiableAndDistance::kNearest(distances, this->k);
}

// classifier by manhattan metric
string ClassifierKnn::classifierManhattan(){
    int length = (this->classifiableObjectsVector).size();
    vector<ClassifiableAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(ClassifiableAndDistance((this->classifiableObjectsVector)[i],
                                                    (this->toClassifier).manhattanDistance((this->classifiableObjectsVector)[i])));
    }
    return ClassifiableAndDistance::kNearest(distances, this->k);
}

// classifier by chebyshev metric
string ClassifierKnn::classifierChebyshev(){
    int length = (this->classifiableObjectsVector).size();
    vector<ClassifiableAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(ClassifiableAndDistance((this->classifiableObjectsVector)[i],
                                                    (this->toClassifier).chebyshevDistance((this->classifiableObjectsVector)[i])));
    }
    return ClassifiableAndDistance::kNearest(distances, this->k);
}

// A function that returns the type of the object (after classification) according to
// the given ClassifierParameters object.
string ClassifierKnn::classify(ClassifierParameters cp) {
    this->k = cp.getK();
    if (cp.getMetric() == "EUC") {
        return this->classifierEuclidean();
    }
    if (cp.getMetric() == "MAN") {
        return this->classifierManhattan();
    }
    if (cp.getMetric() == "CHE") {
        return this->classifierChebyshev();
    }
}

// A public static function that converts a string into a classifiable object.
Classifiable ClassifierKnn::stringToClassifiable(std::string* line) {
    stringstream str(*line);
    string word;
    const char delimiter = ',';
    string type; // The type of the classifiableObj-object.
    double traits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int amountOfArgs = count(line->begin(), line->end(), delimiter);
    for(int i = 0; i < amountOfArgs; i++) { // A loop that gathers the data about the object from a sting.
        getline(str, word, ',');
        traits[i] = stod(word);
    }
    getline(str, word, '\n');
    type = word;
    Classifiable cObj(type, traits); // The creation of the object.
    return cObj;
}

// A public static function that creates a database of Classifiable objects with their type.
vector<Classifiable> ClassifierKnn::setupDatabase(std::string data) {
    vector<Classifiable> classifiableObjectsVector;
    std::string delimiter = "\n";
    size_t pos;
    std::string token = data.substr(0, data.find(delimiter));
    while ((pos = data.find(delimiter)) != std::string::npos) {
        token = data.substr(0, data.find(delimiter));
        data.erase(0, pos + delimiter.length());
        classifiableObjectsVector.push_back(ClassifierKnn::stringToClassifiable(&token));
    }
    return classifiableObjectsVector;
}
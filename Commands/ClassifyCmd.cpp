//
// Created by Ariel Houri on 8/17/2022.
//
#include <algorithm>
#include <iostream>
#include "Commands/ClassifyCmd.hpp"
#include "Classifier/ClassifierParameters.hpp"
#include "Classifier/ClassifierKnn.hpp"
#include "Server/ClassificationFiles.h"

void ClassifyCmd::execute() {
    if (this->files->getClassified() == "" || this->files->getUnClassified() == ""){
        this->dio->write("$please upload files before classifying.$")
        this->dio->read();
        returnl
    }
    this->files->setResults(""); // Empties the results-string.
    std::string classifiedData = this->files->getClassified();
    std::string unclassifiedData = this->files->getUnClassified();
    std::string currentResults = "";
    vector<Classifiable> database = ClassifierKnn::setupDatabase(classifiedData); // Creates the database.
    int i = 1;
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token = unclassifiedData.substr(pos, unclassifiedData.find(delimiter));
    // splits the str to objects according to a delimiter, and classifies every object.
    while ((pos = unclassifiedData.find(delimiter)) != std::string::npos) {
        token = unclassifiedData.substr(0, unclassifiedData.find(delimiter));
        unclassifiedData.erase(0, pos + delimiter.length());
        Classifiable obj = ClassifierKnn::stringToClassifiable(&token, false); // Gets the object to classify,
        std::cout << "the value fo k is: " << cp->getK() << std::endl;
        ClassifierKnn classifier(database, obj, this->cp->getK()); // Creates its classifier.
        // Prints the number, and then the type of the object, from the result the classifier gave.
        currentResults += to_string(i);
        currentResults += "   ";
        currentResults += classifier.classify(*(this->cp));
        currentResults += "\n";
        i++; // Adds one to the counter.
    }
    if (!currentResults.empty()) {
        currentResults.erase(std::prev(currentResults.end()));
    }
    this->files->setResults(currentResults);
    dio->write("$print$Classifying data complete!"); // Notifying that the classification is over.
    dio->read();
}

// A constructor for the Classify Command.
ClassifyCmd::ClassifyCmd(ClassificationFiles* files,
                         ClassifierParameters* cp, DefaultIO* dio) {
    this->cp = cp;
    this->files = files;
    this->description = "classify data";
    this->dio = dio;
}
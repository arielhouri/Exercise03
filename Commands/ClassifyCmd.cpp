//
// Created by Ariel Houri on 8/17/2022.
//

#include <fstream>
#include <sstream>
#include <algorithm>
#include "Commands/ClassifyCmd.hpp"
#include "ClassifierParameters.hpp"
#include "ClassifierKnn.hpp"

void ClassifyCmd::execute() {
    vector<Classifiable> database = ClassifierKnn::setupDatabase(this->classifiedData);
    fstream fRes; // Opens a file to save the results.
    fRes.open("../res.csv", fstream::in | fstream::out | fstream::trunc);
    fstream fin; // Opens the unclassified-data file.
    fin.open(*this->unclassifiedData, fstream::in);
    string line;
    int i = 1;
    while(getline(fin, line)){ // Classifies every object and prints it into the file.
        Classifiable obj = ClassifierKnn::stringToClassifiable(&line); // Gets the object to classify,
        ClassifierKnn classifier(database, obj, 1); // Creates its classifier.
        // Prints the number, and then the type of the object, from the result the classifier gave.
        fRes << to_string(i) << "   " << classifier.classify(*(this->cp)) << endl;
        i++; // Adds one to the counter.
    }
    fRes.close();
    fin.close();
    this->dio->write("Classifying data complete!"); // Notifying that the classification is over.
}


// A constructor for the Classify Command.
ClassifyCmd::ClassifyCmd(std::string* classifiedData, std::string* unclassifiedData, ClassifierParameters* cp, DefaultIO* dio) {
    this->description = "classify data";
    this->dio = dio;
    this->classifiedData = classifiedData;
    this->unclassifiedData = unclassifiedData;
    this->cp = cp;
}

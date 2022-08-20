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
    currentResults = ""; // Empties the results-string.
    vector<Classifiable> database = ClassifierKnn::setupDatabase(&(this->classifiedData));
    fstream fin; // Opens the unclassified-data file.
    fin.open(this->unclassifiedData, fstream::in);
    string line;
    int i = 1;
    while(getline(fin, line)){ // Classifies every object and prints it into the file.
        Classifiable obj = ClassifierKnn::stringToClassifiable(&line); // Gets the object to classify,
        ClassifierKnn classifier(database, obj, 1); // Creates its classifier.
        // Prints the number, and then the type of the object, from the result the classifier gave.
        currentResults += to_string(i);
        currentResults += "   ";
        currentResults += classifier.classify(this->cp);
        currentResults += "\n";
        i++; // Adds one to the counter.
    }
    fin.close();
    this->dio->write("Classifying data complete!"); // Notifying that the classification is over.
}


// A constructor for the Classify Command.
ClassifyCmd::ClassifyCmd(std::string& currentResults, std::string& classifiedData, std::string& unclassifiedData,
                         ClassifierParameters& cp,DefaultIO* dio) : classifiedData(classifiedData),
                         unclassifiedData(unclassifiedData), cp(cp), currentResults(currentResults) {
    this->description = "classify data";
    this->dio = dio;
}

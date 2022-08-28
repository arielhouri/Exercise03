//
// Created by Ariel Houri on 8/17/2022.
//

#include <algorithm>
#include "Commands/ClassifyCmd.hpp"
#include "ClassifierParameters.hpp"
#include "ClassifierKnn.hpp"

void ClassifyCmd::execute() {
    currentResults = ""; // Empties the results-string.
    vector<Classifiable> database = ClassifierKnn::setupDatabase(classifiedData); // Creates the database.
    int i = 1;
    std::string delimiter = "\n";
    size_t pos = 0;
    std::string token = unclassifiedData.substr(pos, unclassifiedData.find(delimiter));
    // splits the str to objects according to a delimiter, and classifies every object.
    while ((pos = unclassifiedData.find(delimiter)) != std::string::npos) {
        token = unclassifiedData.substr(0, unclassifiedData.find(delimiter));
        unclassifiedData.erase(0, pos + delimiter.length());
        Classifiable obj = ClassifierKnn::stringToClassifiable(&token); // Gets the object to classify,
        ClassifierKnn classifier(database, obj, 1); // Creates its classifier.
        // Prints the number, and then the type of the object, from the result the classifier gave.
        currentResults += to_string(i);
        currentResults += "   ";
        currentResults += classifier.classify(this->cp);
        currentResults += "\n";
        i++; // Adds one to the counter.
    }
    dio->write("$print$");
    this->dio->write("Classifying data complete!"); // Notifying that the classification is over.
}


// A constructor for the Classify Command.
ClassifyCmd::ClassifyCmd(std::string& currentResults, std::string& classifiedData, std::string unclassifiedData,
                         ClassifierParameters& cp, DefaultIO* dio) : classifiedData(classifiedData),
                         unclassifiedData(unclassifiedData), cp(cp), currentResults(currentResults) {
    this->description = "classify data";
    this->dio = dio;
}

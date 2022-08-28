//
// Created by ariel on 8/19/2022.
//

#include <fstream>
#include "ConfusionMatrixCmd.hpp"
#include "ClassifierKnn.hpp"
#include <algorithm>

ConfusionMatrixCmd::ConfusionMatrixCmd(std::string& classified, std::string& unclassified,
                                       ClassifierParameters& newClassParams, DefaultIO* dio) :
        classified(classified), unclassified(unclassified), classParams(newClassParams) {
    this->description = "display algorithm confusion matrix";
    this->dio = dio;
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

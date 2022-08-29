//
// Created by Ariel Houri on 8/17/2022.
//

#include <iostream>
#include "ClassifierParameters.hpp"


ClassifierParameters::ClassifierParameters() {
    this->metric = "EUC";
    this->k = 5;
}

int ClassifierParameters::setK(int num) {
    if (num < 1 || num > 10) { // Checking for errors.
        return -1;
    }
    this->k = num; // Setting the new value.
    return 1;
}

int ClassifierParameters::getK() {
    return this->k;
}

int ClassifierParameters::setMetric(std::string newMetric) {
    if (newMetric == "EUC" || newMetric == "MAN" || newMetric == "CHE") {
        this->metric = newMetric;
        return 1;
    }
    return -1;
}

std::string ClassifierParameters::getMetric() {
    return this->metric;
}

std::string ClassifierParameters::getStringRepresentation() {
    std::string str = "The current KNN parameters are: K = "; // Building the string-representation.
    str += std::to_string(this->k);
    str += ", distance metric = ";
    str += metric;
    return str;
}
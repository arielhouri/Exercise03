//
// Created by Ariel Houri on 8/17/2022.
//

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
    return 0;
}

int ClassifierParameters::getK() {
    return this->k;
}

int ClassifierParameters::setMetric(std::string newMetric) {
    if (newMetric == "EUC" || newMetric == "MAN" || newMetric == "CHE") {
        this->metric = newMetric;
        return 0;
    }
    return -1;
}
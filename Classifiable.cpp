//
// Created by Ariel Houri on 7/21/2022.
//

#include "Classifiable.hpp"
#include <algorithm>
#include <cmath>

using namespace std;

// A constructor for an Classifiable that doesn't get any parameters.
Classifiable::Classifiable() {
    this->type = "Unclassified"; // Default type.
    for ( int i = 0; i < 10; i++) {
        traits[i] = 0;
    }
}

// A constructor for an Classifiable that gets its type and measurements for the leafs.
Classifiable::Classifiable(string type, const double newTraits[10]) {
    this->type = type;
    for ( int i = 0; i < 10; i++) {
        this->traits[i] = newTraits[i];
    }
}

// A function that returns the type of the Classifiable.
string Classifiable::getType() const {
    return this->type;
}

double* Classifiable::getTraits() {
    return traits;
}

// A function that measures the distance between the flower and another according to Euclidean Distance.
double Classifiable::euclideanDistance(Classifiable &other) {
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += pow(this->getTraits()[i] - other.getTraits()[i], 2);
    }
    return sqrt(sum);
}

// A function that measures the distance between the flower and another according to Manhattan Distance.
double Classifiable::manhattanDistance(Classifiable &other) {
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += abs(this->getTraits()[i] - other.getTraits()[i]);
    }
    return sum;
}

// A function that measures the distance between the flower and another according to Chebyshev Distance.
double Classifiable::chebyshevDistance(Classifiable &other) {
    double max = 0;
    for (int i = 0; i < 10; ++i) {
        if (abs(this->getTraits()[i] - other.getTraits()[i]) > max) {
            max = abs(this->getTraits()[i] - other.getTraits()[i]);
        }
    }
    return max;
}

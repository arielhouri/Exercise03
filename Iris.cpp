//
// Created by Ariel Houri on 7/21/2022.
//

#include "Iris.hpp"
#include <algorithm>
#include <cmath>

using namespace std;

// A constructor for an Iris that doesn't get any parameters.
Iris::Iris() {
    this->type = "Unclassified"; // Default type.
    this->traits = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

// A constructor for an Iris that gets its type and measurements for the leafs.
Iris::Iris(string type, double traits[10]) {
    this->type = type;
    this->traits = traits;
}

// A function that returns the type of the Iris.
string Iris::getType() const {
    return this->type;
}

double Iris::getTraits() const {
    return this->traits;
}

// A function that measures the distance between the flower and another according to Euclidean Distance.
double Iris::euclideanDistance(const Iris &other) const {
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += pow(this->getTraits()[i] - other.getTraits()[i], 2);
    }
    return sqrt(sum);
}

// A function that measures the distance between the flower and another according to Manhattan Distance.
double Iris::manhattanDistance(const Iris &other) const {
    double sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += abs(this->getTraits()[i] - other.getTraits()[i]);
    }
    return sum;
}

// A function that measures the distance between the flower and another according to Chebyshev Distance.
double Iris::chebyshevDistance(const Iris &other) const {
    double max = 0;
    for (int i = 0; i < 10; ++i) {
        if (abs(this->getTraits()[i] - other.getTraits()[i]) > max) {
            max = abs(this->getTraits()[i] - other.getTraits()[i]);
        }
    }
    return max;
}

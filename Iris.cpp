//
// Created by ariel on 7/21/2022.
//

#include "Iris.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// A constructor for an Iris that doesn't get any parameters.
Iris::Iris() {
    this->type = "Unclassified";
    this->topLength = 0;
    this->topWidth = 0;
    this->bottomLength = 0;
    this->bottomWidth = 0;
}

// A constructor for an Iris that gets its type and measurements for the leafs.
Iris::Iris(const string type, double topLength, double topWidth, double bottomLength, double bottomWidth) {
    this->type = type;
    this->topLength = topLength;
    this->topWidth = topWidth;
    this->bottomLength = bottomLength;
    this->bottomWidth = bottomWidth;
}

// A function that returns the type of the Iris.
string Iris::getType() const {
    return this->type;
}

// A function that returns the length of the top leafs.
double Iris::getTopLength() const {
    return this->topLength;
}

// A function that returns the width of the top leafs.
double Iris::getTopWidth() const {
    return this->topWidth;
}

// A function that returns the length of the bottom leafs.
double Iris::getBottomLength() const {
    return this->bottomLength;
}

// A function that returns the width of the bottom leafs.
double Iris::getBottomWidth() const {
    return this->bottomWidth;
}

// A function that measures the distance between the flower and another according to Euclidean Distance.
double Iris::euclideanDistance(const Iris& other) const {
    return sqrt(pow(this->getTopLength() - other.getTopLength(),2) + pow(this->getTopWidth() - other.getTopWidth(),2)
    + pow(this->getBottomWidth() - other.getBottomWidth(),2) + pow(this->getBottomLength() - other.getBottomLength(),2));
}

// A function that measures the distance between the flower and another according to Manhattan Distance.
double Iris::manhattanDistance(const Iris& other) const {
    return abs(this->getTopLength() - other.getTopLength()) + abs(this->getTopWidth() - other.getTopWidth()) +
    abs(this->getBottomWidth() - other.getBottomWidth()) + abs(this->getBottomLength() - other.getBottomLength());
}

// A function that measures the distance between the flower and another according to Chebyshev Distance.
double Iris::chebyshevDistance(const Iris& other) const {
    return max(this->getTopWidth() - other.getTopWidth(), max(this->getBottomWidth() - other.getBottomWidth(),
                                                              max(this->getBottomLength() - other.getBottomLength(),
                                                                  (this->getTopLength() - other.getTopLength()))));
}

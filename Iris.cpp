//
// Created by ariel on 7/21/2022.
//

#include "Iris.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


Iris::Iris(const string& type, double topLength, double topWidth, double bottomLength, double bottomWidth) {
    this->type = type;
    this->topLength = topLength;
    this->topWidth = topWidth;
    this->bottomLength = bottomLength;
    this->bottomWidth = bottomWidth;
}

string Iris::getType() const {
    return this->type;
}

double Iris::getTopLength() const {
    return this->topLength;
}

double Iris::getTopWidth() const {
    return this->topWidth;
}

double Iris::getBottomLength() const {
    return this->bottomLength;
}

double Iris::getBottomWidth() const {
    return this->bottomWidth;
}

double Iris::euclideanDistance(const Iris& other) const {
    return sqrt(pow(this->getTopLength() - other.getTopLength(),2) + pow(this->getTopWidth() - other.getTopWidth(),2)
    + pow(this->getBottomWidth() - other.getBottomWidth(),2) + pow(this->getBottomLength() - other.getBottomLength(),2));
}

double Iris::manhattanDistance(const Iris& other) const {
    return abs(this->getTopLength() - other.getTopLength()) + abs(this->getTopWidth() - other.getTopWidth()) +
    abs(this->getBottomWidth() - other.getBottomWidth()) + abs(this->getBottomLength() - other.getBottomLength());
}

double Iris::chebyshevDistance(const Iris& other) const {
    return max(this->getTopWidth() - other.getTopWidth(), max(this->getBottomWidth() - other.getBottomWidth(),
                                                              max(this->getBottomLength() - other.getBottomLength(),
                                                                  (this->getTopLength() - other.getTopLength()))));
}

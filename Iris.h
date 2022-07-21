//
// Created by ariel on 7/21/2022.
//

#ifndef EXERCISE1_IRIS_H
#define EXERCISE1_IRIS_H
#include <string>

using namespace std;
class Iris {
private:
    std::string type;
    double topLength;
    double topWidth;
    double bottomLength;
    double bottomWidth;
public:

    Iris(const std::string& type, double topLength, double topWidth, double bottomLength, double bottomWidth);

    string getType() const;

    double getTopLength() const;

    double getTopWidth() const;

    double getBottomLength() const;

    double getBottomWidth() const;

    double euclideanDistance(const Iris& other) const;

    double manhattanDistance(const Iris& other) const;

    double chebyshevDistance(const Iris& other) const;
};


#endif //EXERCISE1_IRIS_H

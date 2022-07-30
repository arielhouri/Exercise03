//
// Created by ariel on 7/21/2022.
//

#ifndef EXERCISE1_IRIS_H
#define EXERCISE1_IRIS_H
#include <string>

using namespace std;
class Iris {
private:
    string type;
    double topLength; // The length of the top leafs.
    double topWidth; // The width of the top leafs.
    double bottomLength; // The length of the bottom leafs.
    double bottomWidth; // The width of the bottom leafs.
public:
    Iris();
    Iris(string type, double topLength, double topWidth, double bottomLength, double bottomWidth);
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

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
    double traits[10];
public:
    Iris();
    Iris(string type, double traits[10]);
    string getType() const;
    double getTraits() const;
    double euclideanDistance(const Iris& other) const;
    double manhattanDistance(const Iris& other) const;
    double chebyshevDistance(const Iris& other) const;
};


#endif //EXERCISE1_IRIS_H

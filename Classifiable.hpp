//
// Created by ariel on 7/21/2022.
//

#ifndef EXERCISE1_IRIS_H
#define EXERCISE1_IRIS_H
#include <string>

using namespace std;
class Classifiable {
private:
    string type;
    double traits[10];
public:
    Classifiable();
    Classifiable(string type, const double traits[10]);
    string getType() const;
    double* getTraits();
    double euclideanDistance(Classifiable& other);
    double manhattanDistance(Classifiable& other);
    double chebyshevDistance(Classifiable& other);
};


#endif //EXERCISE1_IRIS_H

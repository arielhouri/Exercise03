//
// Created by ariel on 7/21/2022.
//

#ifndef EXERCISE1_IRIS_H
#define EXERCISE1_IRIS_H


class Iris {
private:
    std::string type;
    double topLength;
    double topWidth;
    double bottomLength;
    double bottomWidth;
public:
    Iris(const std::string& type, double topLength, double topWidth, double bottomLength, double bottomWidth) {}

    std::string getType() const {}

    double getTopLength() const {}

    double getTopWidth() const {}

    double getBottomLength() const {}

    double getBottomWidth() const {}

    double euclideanDistance(Iris other) const {}

    double manhattanDistance(Iris other) const {}

    double ChebyshevDistance(Iris other) const {}
};


#endif //EXERCISE1_IRIS_H

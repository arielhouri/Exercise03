//
// Created by Yonatan Semidubersky on 21/07/2022.
//

#ifndef EX1_CLASSIFIERKNN_H
#define EX1_CLASSIFIERKNN_H
#include <string>
#include <vector>
#include "Classifiable.hpp"
#include "ClassifiableAndDistance.hpp"
#include "ClassifierParameters.hpp"

using namespace std;
class ClassifierKnn {
private:
    vector<Classifiable> classifiableObjectsVector; // classifiableObjectsVector.
    Classifiable toClassifier; // classifiableObj to class (unknown type).
    int k; // the amount of classifiableObjectsVector that the classifier will use.
public:
    ClassifierKnn(vector<Classifiable>& classifiableObjectsVector, Classifiable& toClassifier, int k);
    string classifierEuclidean();
    string classifierManhattan();
    string classifierChebyshev();
    string classify(ClassifierParameters cp);
    static vector<Classifiable> setupDatabase(std::string data);
    static Classifiable stringToClassifiable(std::string* line);
};

#endif //EX1_CLASSIFIERKNN_H

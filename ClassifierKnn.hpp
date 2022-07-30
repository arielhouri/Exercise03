//
// Created by Yonatan Semidubersky on 21/07/2022.
//

#ifndef EX1_CLASSIFIERKNN_H
#define EX1_CLASSIFIERKNN_H
#include <string>
#include <vector>
#include "Iris.h"
#include "IrisAndDistance.h"

using namespace std;
class ClassifierKnn {
private:
    vector<Iris> flowers; // flowers.
    Iris toClassifier; // flower to class (unknown type).
    int k; // the amount of flowers that the classifier will use.

public:
    ClassifierKnn(vector<Iris>& flowers, Iris& toClassifier, int k);
    string classifierEuclidean();
    string classifierManhattan();
    string classifierChebyshev();
};

#endif //EX1_CLASSIFIERKNN_H

//
// Created by Yonatan Semidubersky on 21/07/2022.
//

#ifndef EX1_CLASSIFIERKNN_H
#define EX1_CLASSIFIERKNN_H
#include <string>

using namespace std2
class ClassifierKnn {
private:
    Iris [] flowers; // flowers.
    Iris toClassifier; // flower to class (unknown type).
    int k; // for finding k closest neighbors.
    string[] kNearest();
public:
    ClassifierKnn(Iris[] flowers, Iris toClassifier, int k);
    string classifierEuclidean();
    string classifierManhattan();
    string classifierChebyshev();
};


#endif //EX1_CLASSIFIERKNN_H

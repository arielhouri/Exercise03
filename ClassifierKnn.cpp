//
// Created by yonat on 21/07/2022.
//

#include "ClassifierKnn.h"
#include <string>

using namespace std2;

ClassifierKnn:: ClassifierKnn(Iris[] flowers, Iris toClassifier, int k){
    this->flowers = flowers;
    this->toClassifier = toClassifier;
    this->k = k;
}
string classifierEuclidean(){
    int length = sizeof(this->flowes)/sizeof(*this->flowes);

    for (int i = 0; i < length; i++){

    }
}
string classifierManhattan();
string classifierChebyshev();

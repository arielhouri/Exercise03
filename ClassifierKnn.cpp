//
// Created by yonat on 21/07/2022.
//

#include "ClassifierKnn.h"
#include "IrisAndDistance.h"
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

ClassifierKnn::ClassifierKnn(vector<Iris>& flowers, Iris& toClassifier, int k){
    this->flowers = flowers;
    this->toClassifier = toClassifier;
    this->k = k;
}

string ClassifierKnn::classifierEuclidean(){
    int length = (this->flowers).size();
    vector<IrisAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(new IrisAndDistance((this->flowers)[i],
                                     (this->toClassifier).euclideanDistance((this->flowers)[i])));
    }
    return IrisAndDistance::kNearest(distances,this->k);
}

string ClassifierKnn::classifierManhattan(){
    int length = (this->flowers).size();
    vector<IrisAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(new IrisAndDistance((this->flowers)[i],
                                                (this->toClassifier).manhattanDistance((this->flowers)[i])));
    }
    return IrisAndDistance::kNearest(distances,this->k);
}
string ClassifierKnn::classifierChebyshev(){
    int length = (this->flowers).size();
    vector<IrisAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(new IrisAndDistance((this->flowers)[i],
                                                (this->toClassifier).chebyshevDistance((this->flowers)[i])));
    }
    return IrisAndDistance::kNearest(distances,this->k);
}

//
// Created by yonat on 21/07/2022.
//

#include "ClassifierKnn.hpp"
#include <algorithm>


using namespace std;
// constructor
ClassifierKnn::ClassifierKnn(vector<Classifiable>& flowers, Classifiable& toClassifier, int k){
    this->flowers = flowers;
    this->toClassifier = toClassifier;
    this->k = k;
}
// classifier by euclidean metric
string ClassifierKnn::classifierEuclidean(){
    int length = (this->flowers).size();
    vector<IrisAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(IrisAndDistance((this->flowers)[i],
                                            (this->toClassifier).euclideanDistance((this->flowers)[i])));
    }
    return IrisAndDistance::kNearest(distances,this->k);
}
// classifier by manhattan metric
string ClassifierKnn::classifierManhattan(){
    int length = (this->flowers).size();
    vector<IrisAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(IrisAndDistance((this->flowers)[i],
                                            (this->toClassifier).manhattanDistance((this->flowers)[i])));
    }
    return IrisAndDistance::kNearest(distances,this->k);
}
// classifier by chebyshev metric
string ClassifierKnn::classifierChebyshev(){
    int length = (this->flowers).size();
    vector<IrisAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(IrisAndDistance((this->flowers)[i],
                                            (this->toClassifier).chebyshevDistance((this->flowers)[i])));
    }
    return IrisAndDistance::kNearest(distances,this->k);
}
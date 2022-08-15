//
// Created by Yonatan Semidubersky on 21/07/2022.
//

#include "ClassifierKnn.hpp"
#include <algorithm>


using namespace std;
// constructor
ClassifierKnn::ClassifierKnn(vector<Classifiable>& classifiableObjectsVector, Classifiable& toClassifier, int k){
    this->classifiableObjectsVector = classifiableObjectsVector;
    this->toClassifier = toClassifier;
    this->k = k;
}
// classifier by euclidean metric
string ClassifierKnn::classifierEuclidean(){
    int length = (this->classifiableObjectsVector).size();
    vector<ClassifiableAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(ClassifiableAndDistance((this->classifiableObjectsVector)[i],
                                                    (this->toClassifier).euclideanDistance((this->classifiableObjectsVector)[i])));
    }
    return ClassifiableAndDistance::kNearest(distances, this->k);
}
// classifier by manhattan metric
string ClassifierKnn::classifierManhattan(){
    int length = (this->classifiableObjectsVector).size();
    vector<ClassifiableAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(ClassifiableAndDistance((this->classifiableObjectsVector)[i],
                                                    (this->toClassifier).manhattanDistance((this->classifiableObjectsVector)[i])));
    }
    return ClassifiableAndDistance::kNearest(distances, this->k);
}
// classifier by chebyshev metric
string ClassifierKnn::classifierChebyshev(){
    int length = (this->classifiableObjectsVector).size();
    vector<ClassifiableAndDistance> distances;
    for (int i = 0; i < length; i++){
        distances.push_back(ClassifiableAndDistance((this->classifiableObjectsVector)[i],
                                                    (this->toClassifier).chebyshevDistance((this->classifiableObjectsVector)[i])));
    }
    return ClassifiableAndDistance::kNearest(distances, this->k);
}
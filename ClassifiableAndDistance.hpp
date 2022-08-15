//
// Created by Yonatan Semidubersky on 22/07/2022.
//
// Classifiable&Distance class will store classifiableObjectsVector and their distances from the point,
// also have a method that find k nearest neighbors to classify classifiableObj.
#ifndef EXERCISE01_IRISANDDISTANCE_H
#define EXERCISE01_IRISANDDISTANCE_H

#include <vector>
#include "Classifiable.hpp"

using namespace std;
class ClassifiableAndDistance {
private:
    Classifiable classifiableObj;
    double distance;
public:
    ClassifiableAndDistance(Classifiable& classifiable, double distance);
    Classifiable getClassifiableObj()const;
    double getDistance()const;
    static string kNearest(vector<ClassifiableAndDistance> v, int k);
    ClassifiableAndDistance(ClassifiableAndDistance* pDistance);
};


#endif //EXERCISE01_IRISANDDISTANCE_H

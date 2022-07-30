//
// Created by Yonatan Semidubersky on 22/07/2022.
//
// Iris&Distance class will store flowers and their distances from the point,
// also have a method that find k nearest neighbors to classify flower.
#ifndef EXERCISE01_IRISANDDISTANCE_H
#define EXERCISE01_IRISANDDISTANCE_H

#include <vector>
#include "Iris.hpp"

using namespace std;
class IrisAndDistance {
private:
    Iris flower;
    double distance;
public:
    IrisAndDistance(Iris& flower, double distance);
    Iris getFlower()const;
    double getDistance()const;
    static string kNearest(vector<IrisAndDistance> v, int k);
    IrisAndDistance(IrisAndDistance* pDistance);
};


#endif //EXERCISE01_IRISANDDISTANCE_H

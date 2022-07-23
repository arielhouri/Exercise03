//
// Created by Yonatan Semidubersky on 22/07/2022.
//

#include "IrisAndDistance.h"
#include "Iris.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

IrisAndDistance::IrisAndDistance(Iris& flower, double distance) {
    this->flower = flower;
    this->distance = distance;
}

Iris IrisAndDistance::getFlower() const {
    return this->flower;
}

double IrisAndDistance::getDistance() const {
    return this->distance;
}

struct comparator {
    inline bool operator()(const IrisAndDistance &flower1, IrisAndDistance &flower2) {
        return (flower1.getDistance() < flower2.getDistance());
    }
};



IrisAndDistance::IrisAndDistance(IrisAndDistance *p) {
    this->flower = p->getFlower();
    this->distance = p->getDistance();
}


string IrisAndDistance::kNearest(vector<IrisAndDistance> v, int k) {
    std::sort(v.begin(), v.end(), comparator());
    int versicolor = 0;
    int virginica = 0;
    int setosa = 0;
    for (int i = 1; i <= k; i++) {
        if (v[i].getFlower().getType() == "Iris-versicolor") {
            versicolor++;
        }
        if (v[i].getFlower().getType() == "Iris-virginica") {
            virginica++;
        }
        if (v[i].getFlower().getType() == "Iris-setosa") {
            setosa++;
        }
    }
    if (versicolor >= virginica) {
        if (versicolor >= setosa)
            return "Iris-versicolor";
        else
            return "Iris-setosa";
    } else {
        if (setosa >= virginica)
            return "Iris-setosa";
        else
            return "Iris-virginica";
    }
}

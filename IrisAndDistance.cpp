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

IrisAndDistance::IrisAndDistance(IrisAndDistance *p) {
    this->flower = p->getFlower();
    this->distance = p->getDistance();
}

// help method: sorting the vector by r index -
// greater will be in the right and smaller in the left.
int arrange(vector<IrisAndDistance> v, int l, int r)
{
    int x = v[r].getDistance();
    int temp = l;
    for (int j = l; j <= r - 1; j++) {
        if (v[j].getDistance() <= x) {
            swap(v[temp], v[j]);
            temp++;
        }
    }
    swap(v[temp], v[r-1]);
    return temp;
}

// quick select algorithm - finding the k smallest element.
int kElement(vector<IrisAndDistance> v, int l, int r, int k)
{
    if (k >= 0 && k <= r) {
        // arrange around l.
        int index = arrange(v, l, r);
        if (index - l == k)
            return index;
        // binary search of k:
        if (index - l > k)
            return kElement(v, l, index - 1, k);
        return kElement(v, index + 1, r,
                           k - index + l - 1);
    } else{
        return -1; // wrong value for k. Incorrect input!
    }
}

string IrisAndDistance::kNearest(vector<IrisAndDistance> v, int k) {
    int index = kElement(v,0,v.size() - 1,k);
    int versicolor = 0;
    int virginica = 0;
    int setosa = 0;
    for (int i = 0; i < v.size(); i++) {
        // if the element isn't in the k nearest neighbors.
        if (v[i].getDistance() > v[index].getDistance()){
            continue;
        }
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

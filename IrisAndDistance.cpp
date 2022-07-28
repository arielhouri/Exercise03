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
    int x = arr[r];
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(arr[l], arr[j]);
            l++;
        }
    }
    swap(arr[l], arr[r]);
    return l;
}
// quick select algorithm - finding the k smallest element.
int kElement(vector<IrisAndDistance> v, int left, int right, int k)
{
    if (k > 0 && k <= r - l + 1) {
        // arrange around l.
        int index = arrange(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        // binary search of k:
        if (index - l > k - 1)
            return kElement(arr, l, index - 1, k);
        return kElement(arr, index + 1, r,
                           k - index + l - 1);
    } else{
        return -1; // wrong value for k.
    }
}

string IrisAndDistance::kNearest(vector<IrisAndDistance> v, int k) {
    int index = kthSmallest(v,0,v.size(),k);
    int versicolor = 0;
    int virginica = 0;
    int setosa = 0;
    for (int i = 0; i <= v.size(); i++) {
        // if the element isn't in the k nearest neighbors.
        if (v[i] > v[index]){
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

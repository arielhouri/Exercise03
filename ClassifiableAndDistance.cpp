//
// Created by Yonatan Semidubersky on 22/07/2022.
//

#include "ClassifiableAndDistance.hpp"
#include <algorithm>

using namespace std;
// constructor
ClassifiableAndDistance::ClassifiableAndDistance(Classifiable& classifiable, double distance) {
    this->classifiableObj = classifiable;
    this->distance = distance;
}
// getter function
Classifiable ClassifiableAndDistance::getClassifiableObj() const {
    return this->classifiableObj;
}
// getter function
double ClassifiableAndDistance::getDistance() const {
    return this->distance;
}
// copy constructor
ClassifiableAndDistance::ClassifiableAndDistance(ClassifiableAndDistance *p) {
    this->classifiableObj = p->getClassifiableObj();
    this->distance = p->getDistance();
}

// help method: sorting the vector by r index -
// greater will be in the right and smaller in the left.
int arrange(vector<ClassifiableAndDistance> *v, int l, int r)
{
    double x = (*v)[r].getDistance();
    int pivot1 = l;
    for (int j = l; j <= r - 1; j++) {
        if ((*v)[j].getDistance() <= x) {
            ClassifiableAndDistance v1 = (*v)[pivot1];
            (*v)[pivot1] = (*v)[j];
            (*v)[j] = v1;
            pivot1++;
        }
    }
    swap((*v)[pivot1], (*v)[r]);
    return pivot1;
}

// quick select algorithm - finding the k-smallest element.
int kElement(vector<ClassifiableAndDistance> *v, int l, int r, int k)
{
    if (k >= 0 && k <= r - l + 1) {
        if (l == r){
            return l;
        }
        // arrange around l.
        int index = arrange(v, l, r);
        if (index - l == k)
            return index;
        // binary search of k:
        if (index - l > k)
            return kElement(v, l, index - 1, k);
        return kElement(v, index + 1, r,
                        k - (index - l + 1));
    } else{
        return -1; // wrong value for k. Incorrect input!
    }
}
// classifier by kNearest objects.
string ClassifiableAndDistance::kNearest(vector<ClassifiableAndDistance> v, int k) {
    // we search for the k-1 element in V[0,...,n] (easier to understand)
    int index = kElement(&v, 0, v.size() - 1, k - 1);
    int versicolor = 0;
    int virginica = 0;
    int setosa = 0;
    string versi("Classifiable-versicolor");
    string virgi("Classifiable-virginica");
    string setos("Classifiable-setosa");
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getDistance() > v[index].getDistance()) {
            continue;
        }
        if (versi.size() + 1 == v[i].getClassifiableObj().getType().size()) {
            versicolor++;
        }
        if (virgi.size() + 1 == v[i].getClassifiableObj().getType().size()) {
            virginica++;
        }
        if (setos.size() + 1 == v[i].getClassifiableObj().getType().size()) {
            setosa++;
        }
    }
    if (versicolor >= virginica) { // The return value according to the data.
        if (versicolor >= setosa)
            return "Classifiable-versicolor";
        else
            return "Classifiable-setosa";
    } else {
        if (setosa >= virginica)
            return "Classifiable-setosa";
        else
            return "Classifiable-virginica";
    }
}
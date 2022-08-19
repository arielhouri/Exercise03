//
// Created by ariel on 8/17/2022.
//

#ifndef IRIS_CPP_CLASSIFIERPARAMETERS_HPP
#define IRIS_CPP_CLASSIFIERPARAMETERS_HPP


#include <string>

class ClassifierParameters {
    std::string metric;
    int k;
public:
    ClassifierParameters(); // A default Constructor.
    int setK(int num);
    int getK();
    int setMetric(std::string metric);
    std::string getMetric();
};


#endif //IRIS_CPP_CLASSIFIERPARAMETERS_HPP

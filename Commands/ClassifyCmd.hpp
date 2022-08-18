//
// Created by Ariel Houri on 8/17/2022.
//

#ifndef IRIS_CPP_CLASSIFYCMD_HPP
#define IRIS_CPP_CLASSIFYCMD_HPP

#include <vector>
#include "Commands/Command.hpp"
#include "ClassifierParameters.hpp"
#include "Classifiable.hpp"

class ClassifyCmd : Command {
    ClassifierParameters* cp;
    std::string* classifiedData;
    std::string* unclassifiedData;
public:
    void execute() override;
    ClassifyCmd(std::string* classifiedData, std::string* unclassifiedData, ClassifierParameters* cp, DefaultIO* dio);
};


#endif //IRIS_CPP_CLASSIFYCMD_HPP

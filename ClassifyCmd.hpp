//
// Created by ariel on 8/17/2022.
//

#ifndef IRIS_CPP_CLASSIFYCMD_HPP
#define IRIS_CPP_CLASSIFYCMD_HPP

#include "Command.hpp"

class ClassifyCmd : Command {
    std::string* classifiedData;
    std::string* unclassifiedData;
public:
    void execute() override;
    ClassifyCmd(std::string* classifiedData, std::string* unclassifiedData);
};


#endif //IRIS_CPP_CLASSIFYCMD_HPP

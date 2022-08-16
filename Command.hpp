//
// Created by Ariel Houri on 8/16/2022.
//

#ifndef IRIS_CPP_COMMAND_HPP
#define IRIS_CPP_COMMAND_HPP
#include <string>
#include "DefaultIO.hpp"


class Command {
    std::string description;
    DefaultIO* dio;
public:
    virtual void execute() = 0; // An abstract function.
};


#endif //IRIS_CPP_COMMAND_HPP

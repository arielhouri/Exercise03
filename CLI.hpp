//
// Created by ariel on 8/16/2022.
//

#ifndef IRIS_CPP_CLI_HPP
#define IRIS_CPP_CLI_HPP

#include "Commands/Command.hpp"

class CLI {
    Command** commands;

public:
    void start();
};


#endif //IRIS_CPP_CLI_HPP

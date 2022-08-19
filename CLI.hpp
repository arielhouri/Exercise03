//
// Created by Yonatan Semidubersky on 8/16/2022.
//

#ifndef IRIS_CPP_CLI_HPP
#define IRIS_CPP_CLI_HPP

#include "Commands/Command.hpp"
#include "ClassifierParameters.hpp"
class CLI {
    Command** commands;
    DefaultIO* io;
    std::string pathFile;
    std::string pathClassified;
    ClassifierParameters parameters;
    std::string results;
    bool shouldStop;
public:
    CLI(DefaultIO io,std::string classifiedPath);
    void start();
};


#endif //IRIS_CPP_CLI_HPP

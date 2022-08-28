//
// Created by Yonatan Semidubersky on 8/16/2022.
//

#ifndef IRIS_CPP_CLI_HPP
#define IRIS_CPP_CLI_HPP

#include "Commands/Command.hpp"
#include "Classifier/ClassifierParameters.hpp"
class CLI {
    Command** commands;
    DefaultIO* sio;
    ClassifierParameters parameters;
    std::string results;
    std::string classifiedData;
    std::string unclassifiedData;
    bool shouldStop;
public:
    CLI(DefaultIO* sio);
    void start();
};


#endif //IRIS_CPP_CLI_HPP

//
// Created by ariel on 8/17/2022.
//

#ifndef IRIS_CPP_ALGOSETTINGSCMD_HPP
#define IRIS_CPP_ALGOSETTINGSCMD_HPP

#include "Command.hpp"
#include "../Classifier/ClassifierParameters.hpp"

class AlgoSettingsCmd : public Command {
    ClassifierParameters* classParams;
public:
    AlgoSettingsCmd(ClassifierParameters* newClassParams, DefaultIO* dio);
    void execute() override;
};


#endif //IRIS_CPP_ALGOSETTINGSCMD_HPP

//
// Created by ariel on 8/19/2022.
//

#ifndef CLASSIFIABLE_CPP_CONFUSIONMATRIXCMD_HPP
#define CLASSIFIABLE_CPP_CONFUSIONMATRIXCMD_HPP

#include "Command.hpp"
#include "Classifier/ClassifierParameters.hpp"
#include <vector>
#include "Server/ClassificationFiles.h"

class ConfusionMatrixCmd : public Command {
    ClassificationFiles* files;
    std::vector<std::string> types;
    ClassifierParameters classParams;
public:
    void execute() override;
    ConfusionMatrixCmd(ClassificationFiles* files, ClassifierParameters& newClassParams, DefaultIO* dio);
};


#endif //CLASSIFIABLE_CPP_CONFUSIONMATRIXCMD_HPP

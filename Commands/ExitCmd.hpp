//
// Created by ariel on 8/27/2022.
//

#ifndef CLASSIFIABLE_CPP_EXITCMD_HPP
#define CLASSIFIABLE_CPP_EXITCMD_HPP

#include "Command.hpp"
#include "../Classifier/ClassifierParameters.hpp"
#include "../Server/ClassificationFiles.hpp"

class ExitCmd : public Command {
    ClassifierParameters* cp;
    ClassificationFiles* cf;
    Command** cmds;
    bool* shouldStop;
public:
    void execute() override;
    ExitCmd(DefaultIO* dio, ClassifierParameters* cp, ClassificationFiles* cf, Command** cmds, bool* shouldStop);
};


#endif //CLASSIFIABLE_CPP_EXITCMD_HPP

//
// Created by ariel on 8/27/2022.
//

#ifndef CLASSIFIABLE_CPP_EXITCMD_HPP
#define CLASSIFIABLE_CPP_EXITCMD_HPP

#include "Command.hpp"

class ExitCmd : public Command {
public:
    void execute() override;
    ExitCmd(DefaultIO* dio);
};


#endif //CLASSIFIABLE_CPP_EXITCMD_HPP

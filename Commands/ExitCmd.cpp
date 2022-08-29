//
// Created by ariel on 8/27/2022.
//

#include "ExitCmd.hpp"

ExitCmd::ExitCmd(DefaultIO* dio, ClassifierParameters* cp, ClassificationFiles* cf, Command** cmds) {
    this->cp = cp;
    this->cf = cf;
    this->cmds = cmds;
    this->dio = dio;
    this->description = "exit";
}

void ExitCmd::execute() {
    delete this->cp; // Frees all the memory.
    delete this->cf;
    delete this->cmds[0];
    delete this->cmds[1];
    delete this->cmds[2];
    delete this->cmds[3];
    delete this->cmds[4];
    delete this->cmds[5];
    delete this->cmds[6];
    delete this->cmds;
    dio->write("$exit$");
}

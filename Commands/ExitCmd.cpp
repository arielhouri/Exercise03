//
// Created by ariel on 8/27/2022.
//

#include "ExitCmd.hpp"

ExitCmd::ExitCmd(DefaultIO* dio, ClassifierParameters* cp, ClassificationFiles* cf, Command** cmds, bool* shouldStop) {
    this->cp = cp;
    this->cf = cf;
    this->cmds = cmds;
    this->dio = dio;
    this->shouldStop = shouldStop;
    this->description = "exit";
}

void ExitCmd::execute() {
    delete this->cp; // Frees all the memory.
    delete this->cf;
    for (int i = 0; i < 7; i++) { // Frees the actual commands.
        delete this->cmds[i];
    }
    delete this->cmds; // Frees the commands-arr
    dio->write("$exit$");
    *(this->shouldStop) = true;
}
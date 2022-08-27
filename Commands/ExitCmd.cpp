//
// Created by ariel on 8/27/2022.
//

#include "ExitCmd.hpp"

ExitCmd::ExitCmd(DefaultIO* dio) {
    this->dio = dio;
    this->description = "exit";
}

void ExitCmd::execute() {
    dio->write("$exit$");
}

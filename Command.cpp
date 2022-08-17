//
// Created by Ariel Houri on 8/16/2022.
//

#include "Command.hpp"

// A function that returns the command's description.
std::string Command::getDescription() {
    return this->description;
}

// A function that returns the command's IO.
DefaultIO* Command::getDefaultIO() {
    return this->dio;
}

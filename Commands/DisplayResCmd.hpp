//
// Created by Ariel Houri on 8/18/2022.
//

#ifndef IRIS_CPP_DISPLAYRESCMD_HPP
#define IRIS_CPP_DISPLAYRESCMD_HPP

#include "Command.hpp"

class DisplayResCmd : Command{
    std::string resultsPath;
public:
    void execute() override;
    DisplayResCmd(std::string& resultsPath, DefaultIO* dio);
};


#endif //IRIS_CPP_DISPLAYRESCMD_HPP

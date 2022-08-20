//
// Created by Ariel Houri on 8/18/2022.
//

#ifndef IRIS_CPP_DISPLAYRESCMD_HPP
#define IRIS_CPP_DISPLAYRESCMD_HPP

#include "Command.hpp"

class DisplayResCmd : public Command{
    std::string results;
public:
    void execute() override;
    DisplayResCmd(std::string& results, DefaultIO* dio);
};


#endif //IRIS_CPP_DISPLAYRESCMD_HPP

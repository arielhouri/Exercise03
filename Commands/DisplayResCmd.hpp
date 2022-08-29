//
// Created by Ariel Houri on 8/18/2022.
//

#ifndef IRIS_CPP_DISPLAYRESCMD_HPP
#define IRIS_CPP_DISPLAYRESCMD_HPP

#include "Command.hpp"
#include "Server/ClassificationFiles.h"
class DisplayResCmd : public Command{
    ClassificationFiles* files;
public:
    void execute() override;
    DisplayResCmd(ClassificationFiles* files, DefaultIO* dio);
};


#endif //IRIS_CPP_DISPLAYRESCMD_HPP

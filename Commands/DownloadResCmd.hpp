//
// Created by ariel on 8/18/2022.
//

#ifndef IRIS_CPP_DOWNLOADRESCMD_HPP
#define IRIS_CPP_DOWNLOADRESCMD_HPP


#include "Command.hpp"
#include "Server/ClassificationFiles.h"
class DownloadResCmd : public Command {
    ClassificationFiles* files;
public:
    DownloadResCmd(ClassificationFiles* files, DefaultIO* dio);
    void execute() override;
};


#endif //IRIS_CPP_DOWNLOADRESCMD_HPP

//
// Created by Ariel Houri on 8/20/2022.
//

#ifndef CLASSIFIABLE_CPP_UPLOADCMD_HPP
#define CLASSIFIABLE_CPP_UPLOADCMD_HPP

#include "Command.hpp"
#include "../Server/ClassificationFiles.hpp"
class UploadCmd : public Command {
    ClassificationFiles* files;
public:
    void execute() override;
    UploadCmd(ClassificationFiles* files, DefaultIO* dio);
};


#endif //CLASSIFIABLE_CPP_UPLOADCMD_HPP

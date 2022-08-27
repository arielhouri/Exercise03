//
// Created by ariel on 8/20/2022.
//

#ifndef CLASSIFIABLE_CPP_UPLOADCMD_HPP
#define CLASSIFIABLE_CPP_UPLOADCMD_HPP

#include "Command.hpp"

class UploadCmd : public Command {
    std::string classifiedData;
    std::string unclassifiedData;
public:
    void execute() override;
    UploadCmd(std::string& classifiedData, std::string& unclassifiedData, DefaultIO* dio);
};


#endif //CLASSIFIABLE_CPP_UPLOADCMD_HPP

//
// Created by ariel on 8/18/2022.
//

#ifndef IRIS_CPP_DOWNLOADRESCMD_HPP
#define IRIS_CPP_DOWNLOADRESCMD_HPP


#include "Command.hpp"

class DownloadResCmd : public Command {
    std::string results;
public:
    DownloadResCmd(std::string& results, DefaultIO* dio);
    void execute() override;
};


#endif //IRIS_CPP_DOWNLOADRESCMD_HPP

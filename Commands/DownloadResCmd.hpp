//
// Created by ariel on 8/18/2022.
//

#ifndef IRIS_CPP_DOWNLOADRESCMD_HPP
#define IRIS_CPP_DOWNLOADRESCMD_HPP


#include "Command.hpp"

class DownloadResCmd : Command {
    std::string printPath;
    std::string resPath;
public:
    DownloadResCmd(std::string& outputPath, std::string& resPath, DefaultIO* dio);
    void execute() override;
};


#endif //IRIS_CPP_DOWNLOADRESCMD_HPP

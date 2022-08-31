//
// Created by Yonatan Semidubersky on 8/31/2022.
//

#ifndef CLASSIFIABLE_CPP_CONFUSIONMATRIXCMD_HPP
#define CLASSIFIABLE_CPP_CONFUSIONMATRIXCMD_HPP

#include "Command.hpp"
#include "Classifier/ClassifierParameters.hpp"
#include <vector>
#include "Server/ClassificationFiles.h"
#include "map"
class ConfusionMatrixCmd : public Command {
    ClassificationFiles* files;
    std::vector<std::string> types;
    ClassifierParameters* classParams;
public:
    static int get(const std::string& key, std::map<std::string, int> types);
    static std::map<std::string, int> mapTypes(std::string classified);
    static std::string getType(const std::string& line);
    void execute() override;
    ConfusionMatrixCmd(ClassificationFiles* files, ClassifierParameters* newClassParams, DefaultIO* dio);
};


#endif //CLASSIFIABLE_CPP_CONFUSIONMATRIXCMD_HPP
//
// Created by Ariel Houri on 8/17/2022.
//

#ifndef IRIS_CPP_CLASSIFYCMD_HPP
#define IRIS_CPP_CLASSIFYCMD_HPP

#include <vector>
#include "Command.hpp"
#include "../Classifier/ClassifierParameters.hpp"
#include "../Classifier/Classifiable.hpp"
#include "../Server/ClassificationFiles.hpp"

class ClassifyCmd : public Command {
    ClassifierParameters* cp;
    ClassificationFiles* files;
public:
    void execute() override;
    ClassifyCmd(ClassificationFiles* files,
                ClassifierParameters* cp, DefaultIO* dio);
};


#endif //IRIS_CPP_CLASSIFYCMD_HPP

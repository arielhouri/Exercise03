//
// Created by ariel on 8/17/2022.
//

#include "ClassifyCmd.hpp"

void ClassifyCmd::execute() {

}

ClassifyCmd::ClassifyCmd(std::string* classifiedData, std::string* unclassifiedData) {
    this->classifiedData = classifiedData;
    this->unclassifiedData = unclassifiedData;
}

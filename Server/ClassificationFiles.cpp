//
// Created by yonat on 29/08/2022.
//

#include "ClassificationFiles.hpp"
ClassificationFiles::ClassificationFiles() {
    this->classified = "";
    this->unclassified = "";
    this->results = "";
}

void ClassificationFiles::setClassified(std::string classified){
    this->classified = classified;
}

void ClassificationFiles::setUnClassified(std::string unclassified){
    this->unclassified = unclassified;
}

void ClassificationFiles::setResults(std::string results){
    this->results = results;
}

std::string ClassificationFiles::getClassified(){
    return this->classified;
}

std::string ClassificationFiles::getUnClassified(){
    return this->unclassified;
}

std::string ClassificationFiles::getResults(){
    return this->results;
}
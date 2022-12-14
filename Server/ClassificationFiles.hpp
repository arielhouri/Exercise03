//
// Created by yonat on 29/08/2022.
//

#ifndef EXERCISE03_CLASSIFICATIONFILES_HPP
#define EXERCISE03_CLASSIFICATIONFILES_HPP

#include "string"
// This class saves the classified-data, unclassified-data and the results string.
class ClassificationFiles {
private:
    std::string classified;
    std::string unclassified;
    std::string results;
public:
    ClassificationFiles();
    void setClassified(std::string classified);
    void setUnClassified(std::string unclassified);
    void setResults(std::string results);
    std::string getClassified();
    std::string getUnClassified();
    std::string getResults();
};


#endif //EXERCISE03_CLASSIFICATIONFILES_HPP

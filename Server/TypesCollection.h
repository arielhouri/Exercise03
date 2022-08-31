//
// Created by yonat on 31/08/2022.
//

#ifndef EXERCISE03_TYPESCOLLECTION_H
#define EXERCISE03_TYPESCOLLECTION_H
#include <map>
#include "string"
class TypesCollection {
private:
    std::map<std::string, int> types;
public:
    TypesCollection(std::map<std::string, int> types);
    int get(std::string key);

};


#endif //EXERCISE03_TYPESCOLLECTION_H

//
// Created by yonat on 31/08/2022.
//

#include "TypesCollection.h"
#include "map"
TypesCollection::TypesCollection(std::map<std::string, int> types) {
    this->types = types;
}
int TypesCollection::get(std::string key){
    int index = 0;
    std::map<std::string, int>::iterator itr;
    for (itr = this->types.begin(); itr != this->types.end(); ++itr){
        if (itr->first == key){
            return index;
        }
        index++;
    }
    return -1;
}
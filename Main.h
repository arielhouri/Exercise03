//
// Created by ariel on 7/22/2022.
//

#ifndef EX01_MAIN_H
#define EX01_MAIN_H

#include "Iris.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

class Main {
    vector<Iris> flowerVector;
    int k;

public:
    static vector<Iris> setup();
    static Iris getIris(string& line);
};


#endif //EX01_MAIN_H

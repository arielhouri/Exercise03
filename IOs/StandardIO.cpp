//
// Created by Yonatan Semidubersky on 18/08/2022.
//

#include "StandardIO.hpp"
#include <iostream>
#include <string>
using namespace std;
std::string StandardIO:: read() {
    // reading input and return
    string input;
    cin >> input;
    return input;
}
void StandardIO:: write(std::string toWrite){
    cout << toWrite << endl;
}

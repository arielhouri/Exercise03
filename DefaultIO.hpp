//
// Created by Ariel Houri on 8/16/2022.
//

#ifndef IRIS_CPP_DEFAULTIO_HPP
#define IRIS_CPP_DEFAULTIO_HPP

#include <string>

class DefaultIO {
public:
    virtual std::string read() = 0; // An abstract function.
    virtual void write(std::string toWrite) = 0; // An abstract function.
    virtual std::string readFromFile(std::string address);
    virtual std::string writeToFile(std::string address, std::string msg);
};


#endif //IRIS_CPP_DEFAULTIO_HPP

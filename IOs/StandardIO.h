//
// Created by Yonatan Semidubersky on 18/08/2022.
//

#ifndef EXERCISE03_STANDARDIO_H
#define EXERCISE03_STANDARDIO_H
#include <string>
#include "DefaultIO.hpp"

class StandardIO : public DefaultIO {
public:
    std::string read() override;
    void write(std::string toWrite) override;
};


#endif //EXERCISE03_STANDARDIO_H

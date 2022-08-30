//
// Created by yonat on 30/08/2022.
//

#include "NotifyTimeOut.h"
#include <time.h>
#include <iostream>

NotifyTimeOut::NotifyTimeOut(float secondsTimeOut) {
    this->secondsTimeOut = secondsTimeOut;
    this->begin_time = clock(); // current time
}

bool NotifyTimeOut::shouldStop(){
    std::cout << float(clock () - begin_time) << std::endl;
    return float( clock () - begin_time ) > secondsTimeOut; // if time over
}

void NotifyTimeOut::listenAccepted() {
    this->begin_time = clock(); // reset the timer
}

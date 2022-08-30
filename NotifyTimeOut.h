//
// Created by yonat on 30/08/2022.
//

#ifndef EXERCISE03_NOTIFYTIMEOUT_H
#define EXERCISE03_NOTIFYTIMEOUT_H

#include <time.h>

class NotifyTimeOut {
    clock_t begin_time;
    float secondsTimeOut;
public:
    NotifyTimeOut(float secondsTimeOut);
    void ListenAccepted();
    bool shouldStop();
};


#endif //EXERCISE03_NOTIFYTIMEOUT_H

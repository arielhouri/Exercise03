//
// Created by Ariel Houri on 8/30/2022.
//

#ifndef COMMAND_CPP_CLIENTTHREAD_HPP
#define COMMAND_CPP_CLIENTTHREAD_HPP


#include <pthread.h>

class ClientThread {
    bool withClient;
    bool isThreadActive;
    pthread_attr_t attr;
    pthread_t mainThread;
public:
    ClientThread();
    // Runs the main-thread with a given function.
    int runThread(void* (*routine)(void*), void* args);
    // Runs the sub-thread with a given function.
    bool isRunning();
    void setWithCliet(bool val);
    bool getWithClient();
    void setIsRunning(bool val);
    pthread_t getMainThread();
};


#endif //COMMAND_CPP_CLIENTTHREAD_HPP

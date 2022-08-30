//
// Created by Ariel Houri on 8/30/2022.
//

#ifndef COMMAND_CPP_THREADPAIR_HPP
#define COMMAND_CPP_THREADPAIR_HPP


#include <pthread.h>

class ThreadPair {
    bool isMainActive;
    bool isSubActive;
    pthread_attr_t attr;
    pthread_t mainThread;
    pthread_t subThread;
public:
    ThreadPair();
    // Runs the main-thread with a given function.
    int runMainThread(void* (*routine)(void*), void* args);
    // Runs the sub-thread with a given function.
    int runSubThread(void* (*routine)(void*), void* args);
    bool isRunning();
};


#endif //COMMAND_CPP_THREADPAIR_HPP

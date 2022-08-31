//
// Created by Ariel Houri on 8/30/2022.
//

#ifndef COMMAND_CPP_THREADCONTAINER_HPP
#define COMMAND_CPP_THREADCONTAINER_HPP

#include <pthread.h>
#include <utility>
#include <vector>
#include "ThreadPair.hpp"

class ThreadContainer {
    std::vector<std::pair<ThreadPair, bool>> threadsVector;
    int getAmountOfAvailableThreads();
    void updateThreadContainer();
public:
    ThreadContainer();
    ThreadPair* getAvailableThread();
    void joinAllThreads();
    bool anyRunning();
};


#endif //COMMAND_CPP_THREADCONTAINER_HPP

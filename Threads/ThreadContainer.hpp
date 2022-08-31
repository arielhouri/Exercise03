//
// Created by Ariel Houri on 8/30/2022.
//

#ifndef COMMAND_CPP_THREADCONTAINER_HPP
#define COMMAND_CPP_THREADCONTAINER_HPP

#include <pthread.h>
#include <utility>
#include <vector>
#include "ClientThread.hpp"

class ThreadContainer {
    std::vector<ClientThread> threadsVector;
    int getAmountOfAvailableThreads();
    void updateThreadContainer();
public:
    ThreadContainer();
    ClientThread* getAvailableThread();
    void joinAllClientThreads();
    bool anyRunning();
};


#endif //COMMAND_CPP_THREADCONTAINER_HPP

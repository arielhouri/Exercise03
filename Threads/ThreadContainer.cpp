//
// Created by Ariel Houri on 8/30/2022.
//

#include "ThreadContainer.hpp"
#include <pthread.h>
#include <iostream>


ThreadContainer::ThreadContainer() {
    std::vector<ClientThread> threadsVector1;
    for (int i = 0; i < 3; i++) { // Creates 2 ThreadPairs and adds them to the container.
        ClientThread tPair;
        threadsVector1.push_back(tPair);
    }
    this->threadsVector = threadsVector1;
}

// A private function that gets the amount of nopt-running threads.
int ThreadContainer::getAmountOfAvailableThreads() {
    this->updateThreadContainer();
    int amount = 0;
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!itr->isRunning()) {
            amount++;
        }
    }
    return amount;
}

// Returns an available ClientThread that can be used by the server, function is recursive but will stop after a single call.
ClientThread* ThreadContainer::getAvailableThread() {
    this->updateThreadContainer();
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!itr->isRunning()) { // Checks for available thread.
            itr->setIsRunning(true);
            return &(*itr);
        }
    }
    // In case where all the Tread-Pair are not available, creates a new Tread-Pair and adds it to the container.
    ClientThread tp;
    this->threadsVector.push_back(tp);
    return this->getAvailableThread();
}

// A private function that Updates the Thread-Container's data about running and not threads.
void ThreadContainer::updateThreadContainer() {
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!(itr->isRunning())) { // Checks if the thread is running or not.
            itr->setIsRunning(false);
        }
    }
}

// Returns true if there is a thread that is currently running, false otherwise.
bool ThreadContainer::anyRunning() {
    this->updateThreadContainer();
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (itr->isRunning()) { // Checks if the thread is running or not.
            return true;
        }
    }
    return false;
}

void ThreadContainer::joinAllClientThreads() {
    this->updateThreadContainer();
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (itr->getWithClient()) {
            pthread_join(itr->getMainThread(), NULL);
        }
    }
}
//
// Created by Ariel Houri on 8/30/2022.
//

#include "ThreadContainer.hpp"


ThreadContainer::ThreadContainer() {
    std::vector<std::pair<ThreadPair, bool>> threadsVector1;
    for (int i = 0; i < 10; i++) { // Creates 10 ThreadPairs and adds them to the container.
        ThreadPair tPair;
        std::pair<ThreadPair, bool> pair1;
        pair1.first = tPair;
        pair1.second = false;
        threadsVector1.push_back(pair1);
    }
    this->threadsVector = threadsVector1;
}

int ThreadContainer::getAmountOfAvailableThreads() {
    int amount = 0;
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!itr->second) {
            amount++;
        }
    }
    return amount;
}

// Returns an available ThreadPair that can be used by the server.
ThreadPair* ThreadContainer::getAvailableThreads() {
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!itr->second) { // Checks for available thread.
            itr->second = true;
            return &(itr->first);
        }
    }
}

// Returns true if there are available threads, false otherwise.
bool ThreadContainer::existsAvailableThreads() {
    return (this->getAmountOfAvailableThreads() != 0);
}

// Updates the Thread-Container's data about running and not threads.
void ThreadContainer::updateThreadContainer() {
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!(itr->first.isRunning())) { // Checks if the thread is running or not.
            itr->second = false;
        }
    }
}
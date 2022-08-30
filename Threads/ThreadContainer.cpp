//
// Created by Ariel Houri on 8/30/2022.
//

#include "ThreadContainer.hpp"


ThreadContainer::ThreadContainer() {
    std::vector<std::pair<ThreadPair, bool>> threadsVector1;
    for (int i = 0; i < 2; i++) { // Creates 2 ThreadPairs and adds them to the container.
        ThreadPair tPair;
        std::pair<ThreadPair, bool> pair1;
        pair1.first = tPair;
        pair1.second = false;
        threadsVector1.push_back(pair1);
    }
    this->threadsVector = threadsVector1;
}

// A private function that gets the amount of nopt-running threads.
int ThreadContainer::getAmountOfAvailableThreads() {
    this->updateThreadContainer();
    int amount = 0;
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!itr->second) {
            amount++;
        }
    }
    return amount;
}

// Returns an available ThreadPair that can be used by the server, function is recursive but will stop after a single call.
ThreadPair* ThreadContainer::getAvailableThread() {
    this->updateThreadContainer();
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!itr->second) { // Checks for available thread.
            itr->second = true;
            return &(itr->first);
        }
    }
    // In case where all the Tread-Pair are not available, creates a new Tread-Pair and adds it to the container.
    ThreadPair tp;
    std::pair<ThreadPair, bool> pair1;
    pair1.first = tp;
    pair1.second = false;
    this->threadsVector.push_back(pair1);
    return this->getAvailableThread();
}

// A private function that Updates the Thread-Container's data about running and not threads.
void ThreadContainer::updateThreadContainer() {
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (!(itr->first.isRunning())) { // Checks if the thread is running or not.
            itr->second = false;
        }
    }
}

// Returns true if there is a thread that is currently running, false otherwise.
bool ThreadContainer::anyRunning() {
    this->updateThreadContainer();
    for (auto itr = threadsVector.begin(); itr < threadsVector.end(); itr++) {
        if (itr->first.isRunning()) { // Checks if the thread is running or not.
            return true;
        }
    }
    return false;
}
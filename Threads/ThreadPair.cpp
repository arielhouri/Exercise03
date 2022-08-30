//
// Created by Ariel Houri on 8/30/2022.
//

#include "ThreadPair.hpp"

ThreadPair::ThreadPair() {
    pthread_attr_t attr1;
    this->attr = attr1;
    pthread_attr_init(&attr); // Sets the default attributes of the thread.
    this->isMainActive = false;
    this->isSubActive = false;
    pthread_t mainT, subT;
    this->mainThread = mainT;
    this->subThread = subT;
}

// Runs the main-thread with a given routine and args.
int ThreadPair::runMainThread(void* (*routine)(void*), void* args) {
    if (this->isMainActive) { // Makes sure the thread isn't already running.
        return -1;
    }
    // Runs the thread:
    if (pthread_create(&this->mainThread, &this->attr, routine, args) != 0) {
        return -1;
    }
    pthread_join(this->mainThread, NULL);
    isMainActive = false; // Marks the thread as running.
    return 0;
}

// Runs the main-thread with a given routine and args.
int ThreadPair::runSubThread(void* (*routine)(void*), void* args) {
    // Makes sure the thread isn't already running and that the main-thread isn't terminated.
    if (!this->isMainActive || this->isSubActive) {
        return -1;
    }
    // Runs the thread:
    if (pthread_create(&this->subThread, &this->attr, routine, args) != 0) {
        return -1;
    }
    pthread_join(this->subThread, NULL);
    isSubActive = false; // Marks the thread as running.
    return 0;
}

// Returns true if the main thread is running, false otherwise.
bool ThreadPair::isRunning() {
    return this->isMainActive;
}
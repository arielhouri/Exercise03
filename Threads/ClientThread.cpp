//
// Created by Ariel Houri on 8/30/2022.
//

#include "ClientThread.hpp"
#include <iostream>

ClientThread::ClientThread() {
    pthread_attr_t attr1;
    this->attr = attr1;
    pthread_attr_init(&attr); // Sets the default attributes of the thread.
    this->isThreadActive = false;
    pthread_t mainT, subT;
    this->mainThread = mainT;
    this->withClient = false;
}

// Runs the thread with a given routine and args.
int ClientThread::runThread(void* (*routine)(void*), void* args) {
    if (this->withClient) { // Makes sure the thread isn't already running.
        std::cout << "Thread is already working with a client." << std::endl;
        return -1;
    }
    // Runs the thread:
    if (pthread_create(&this->mainThread, &this->attr, routine, args) != 0) {
        std::cout << "Error creating thread." << std::endl;
        return -1;
    }
    this->withClient = false;
    return 0;
}

// Returns true if the main thread is running, false otherwise.
bool ClientThread::isRunning() {
    return this->isThreadActive;
}

pthread_t ClientThread::getMainThread() {
    return this->mainThread;
}

void ClientThread::setWithCliet(bool val) {
    this->withClient = val;
}

void ClientThread::setIsRunning(bool val) {
    this->isThreadActive = val;
}

bool ClientThread::getWithClient() {
    return this->withClient;
}
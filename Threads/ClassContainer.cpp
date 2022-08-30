//
// Created by ariel on 8/30/2022.
//

#include "ClassContainer.hpp"

NotifyTimeOut* ClassContainer::getNT() {
    return this->nt;
}

ThreadContainer* ClassContainer::getTC() {
    return this->tc;
}

ClassificationServer* ClassContainer::getCS() {
    return this->cs;
}

void ClassContainer::setNT(NotifyTimeOut* nt) {
    this->nt = nt;
}

void ClassContainer::setTC(ThreadContainer* tc) {
    this->tc = tc;
}

void ClassContainer::stcCS(ClassificationServer* cs) {
    this->cs = cs;
}

ClassContainer::ClassContainer(NotifyTimeOut* nt, ThreadContainer* tc, ClassificationServer* cs) {
    this->nt = nt;
    this->tc = tc;
    this->cs = cs;
}

void ClassContainer::notify() {
    ThreadPair *tp = cc.getTC()->getAvailableThread();
    tp->runMainThread(ClassificationServer::startFunc, cc.getCS());
    cc.getNT()->listenAccepted();
    ((ClassificationServer*)(cc.getCS()))->start(); // Function isn't being executed.
}
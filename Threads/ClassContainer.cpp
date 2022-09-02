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

void ClassContainer::setCS(ClassificationServer* cs) {
    this->cs = cs;
}

int* ClassContainer::getNumAddress() {
    return num;
}

void ClassContainer::setNum(int newNum) {
    *(num) = newNum;
}

ClassContainer::~ClassContainer() {
    delete num;
}

ClassContainer::ClassContainer(NotifyTimeOut* nt, ThreadContainer* tc, ClassificationServer* cs) {
    this->num = new int();
    *num = 0;
    this->nt = nt;
    this->tc = tc;
    this->cs = cs;
    this->listening = false;
}

void ClassContainer::setListening(bool val) {
    this->listening = val;
}

bool ClassContainer::isListening() const {
    return this->listening;
}
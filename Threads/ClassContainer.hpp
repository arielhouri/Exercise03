//
// Created by ariel on 8/30/2022.
//

#ifndef COMMAND_CPP_CLASSCONTAINER_HPP
#define COMMAND_CPP_CLASSCONTAINER_HPP


#include "Server/ClassificationServer.hpp"
#include "ThreadContainer.hpp"
#include "Server/NotifyTimeOut.h"

class ClassContainer {
    int* num;
    ClassificationServer* cs;
    NotifyTimeOut* nt;
    ThreadContainer* tc;
    bool listening;
public:
    ClassContainer(NotifyTimeOut *nt, ThreadContainer *tc, ClassificationServer *cs);
    NotifyTimeOut* getNT();
    ThreadContainer* getTC();
    ClassificationServer* getCS();
    void setNT(NotifyTimeOut* nt);
    void setTC(ThreadContainer* tc);
    void setCS(ClassificationServer* cs);
    bool isListening() const;
    void setListening(bool val);
    void setNum(int newNum);
    int* getNumAddress();
};


#endif //COMMAND_CPP_CLASSCONTAINER_HPP

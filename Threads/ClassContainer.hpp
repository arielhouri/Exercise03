//
// Created by ariel on 8/30/2022.
//

#ifndef COMMAND_CPP_CLASSCONTAINER_HPP
#define COMMAND_CPP_CLASSCONTAINER_HPP


#include "Server/ClassificationServer.hpp"
#include "ThreadContainer.hpp"
#include "Server/NotifyTimeOut.h"

class ClassContainer {
    ClassificationServer* cs;
    NotifyTimeOut* nt;
    ThreadContainer* tc;
public:
    ClassContainer(NotifyTimeOut *nt, ThreadContainer *tc, ClassificationServer *cs);
    NotifyTimeOut* getNT();
    ThreadContainer* getTC();
    ClassificationServer* getCS();
    void setNT(NotifyTimeOut* nt);
    void setTC(ThreadContainer* tc);
    void stcCS(ClassificationServer* cs);
};


#endif //COMMAND_CPP_CLASSCONTAINER_HPP

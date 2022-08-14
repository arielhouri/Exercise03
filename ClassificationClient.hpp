//
// Created by yonat on 12/08/2022.
//

#ifndef EXERCISE02_CLASSIFICATIONCLIENT_H
#define EXERCISE02_CLASSIFICATIONCLIENT_H
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


class ClassificationClient {
    void communicateServer();
};


#endif //EXERCISE02_CLASSIFICATIONCLIENT_H

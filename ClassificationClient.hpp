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
    std::string readingFromFile(std::string path);
public:
    void communicateServer(std::string path1, std::string path2);
};


#endif //EXERCISE02_CLASSIFICATIONCLIENT_H

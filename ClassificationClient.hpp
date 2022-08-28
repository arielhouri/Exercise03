//
// Created by yonat on 12/08/2022.
//

#ifndef EXERCISE02_CLASSIFICATIONCLIENT_H
#define EXERCISE02_CLASSIFICATIONCLIENT_H
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>


class ClassificationClient {
    static std::string readingFromFile(const std::string& path);
    static std::string read(int sock);
    static void write(int sock, const std::string& toWrite);
    static std::string commandSplit(std::string message);
    static std::string messageSplit(std::string message);
public:
    static void communicateServer();
};


#endif //EXERCISE02_CLASSIFICATIONCLIENT_H

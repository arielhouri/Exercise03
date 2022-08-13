//
// Created by Ariel Houri on 8/6/2022.
//

#ifndef EX02_CLASSIFICATIONSERVER_HPP
#define EX02_CLASSIFICATIONSERVER_HPP
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include "Iris.hpp"


class ClassificationServer {
    int server_port;
    int socketInt;
    int sizeBuffer;
    struct sockaddr_in sin;
    char buffer[4096];
public:
    ClassificationServer();
    char* getBuffer();
    int getSocketInt() const;
    int getSizeBuffer() const;
    vector<Iris> setup();
    Iris stringToIris(string str) const;
    string convertToString(char* txt);
};


#endif //EX02_CLASSIFICATIONSERVER_HPP

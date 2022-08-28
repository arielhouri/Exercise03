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
#include "Classifier/Classifiable.hpp"


class ClassificationServer {
    int const server_port; // Const because the Server uses a single port.
    int const socketInt; // Const because the Server uses a single socket.
    int sizeBuffer;
    struct sockaddr_in sin;
    char buffer[4096];
    int receiveData(int clientSocket);
    int listenToSocket();
public:
    static string convertToString(char* txt);
    ClassificationServer();
    int start();
};


#endif //EX02_CLASSIFICATIONSERVER_HPP
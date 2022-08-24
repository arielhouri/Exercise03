//
// Created by Yonatan Semidubersky on 25/08/2022.
//

#ifndef EXERCISE03_SOCKETIO_H
#define EXERCISE03_SOCKETIO_H
#include <fstream>
#include <string>
#include "DefaultIO.hpp"
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
class SocketIO : public DefaultIO{
private:
    int port;
    char* id;
public:
    SocketIO(int port,char* id);
    std::string read() override;
    void write(std::string toWrite) override;
};


#endif //EXERCISE03_SOCKETIO_H

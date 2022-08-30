//
// Created by Ariel Houri on 8/6/2022.
//

#include "ClassificationServer.hpp"
#include <sstream>
#include "Commands/Command.hpp"
#include "IOs/SocketIO.h"
#include "CLI.hpp"
#include "Threads/ThreadContainer.hpp"
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ClassificationServer cs;
    ClassificationServer* ptr = &cs;
    ThreadContainer tc;
    NotifyTimeout nt = new NotifyTimeout();
    while (!(nt.shouldStop())) {
        if (cs.listenToSocket() < 0) { // Listening to socket.
            return -1;
        }
        ThreadPair *tp = tc.getAvailableThread();
        tp->runMainThread(ClassificationServer::startFunc, &cs);
        nt.accepted();
    }
}

// A function used for the multi-threading.
void *ClassificationServer::startFunc(void *cs1)  {
    ((ClassificationServer*)cs1)->start(); // Function isn't being executed.
    return nullptr;
}

// A constructor for a ClassificationServer.
ClassificationServer::ClassificationServer() : sizeBuffer(8192), server_port(40022), socketInt(socket(AF_INET,
                                                                                                  SOCK_STREAM, 0)) {
    if (socketInt < 0) {
        cout << "Error creating socket";
        return;
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(socketInt, (struct sockaddr *) &sin, sizeof(sin)) < 0) { // Binding the socket.
        cout << "Error binding socket" << endl;
    }
}

// A function that receives data from a given socket.
int ClassificationServer::receiveData(int clientSock) {
    long read_bytes = recv(clientSock, buffer, sizeBuffer, 0); // Receiving data from the Client.
    if (read_bytes == 0) { // Checking for errors.
        cout << "The connection is closed." << endl;
        return -1;
    }
    else if (read_bytes < 0) {
        cout << "Error reading input." << endl;
        return -1;
    }
    return 1;
}

// The function that runs the program.
int ClassificationServer::start() {
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(this->socketInt, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) { // Checking for errors in the connection.
        cout << "Error accepting client" << endl;
        return -1;
    }
    SocketIO sio(client_sock);
    CLI cli(&sio); // Creating the CLI.
    cli.start();
    return 1;
}

// A function that listens to a socket.
int ClassificationServer::listenToSocket() {
    if (listen(socketInt, 5) < 0) { // Listening to the socket.
        cout << "Error listening to a socket" << endl;
        return -1;
    }
    return 1;
}


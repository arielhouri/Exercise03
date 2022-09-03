//
// Created by Ariel Houri on 8/6/2022.
//

#include "ClassificationServer.hpp"
#include <sstream>
#include "../IOs/SocketIO.hpp"
#include "CLI.hpp"
#include "../Threads/ThreadContainer.hpp"
#include "../Threads/ClassContainer.hpp"
#include "NotifyTimeOut.hpp"
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    ClassificationServer cs;
    ClassificationServer* ptr = &cs;
    ThreadContainer tc;
    auto nt = new NotifyTimeOut(60 * 1000000);
    ClassContainer cc(nt, &tc, ptr);
    // Creating a new thread:
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t thread1;
    pthread_create(&thread1, &attr, ClassificationServer::listenAndAcceptFunc, &cc);
    pthread_join(thread1, NULL);
    delete cc.getNT();
    return 0;
}

// A function used for the multi-threading.
void *ClassificationServer::startFunc(void *cc1)  {
    ((ClassContainer*)cc1)->getCS()->start(((ClassContainer*)cc1)->getNT(), ((ClassContainer*)cc1)->getNumAddress());
    return nullptr;
}

// The function that runs the program.
int ClassificationServer::start(NotifyTimeOut* nt1, int* num) {
    NotifyTimeOut* nt = nt1;
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(this->socketInt, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) { // Checking for errors in the connection.
        cout << "Error accepting client" << endl;
        return -1;
    }
    *(num) = 0;
    nt->listenAccepted();
    SocketIO sio(client_sock);
    CLI cli(&sio); // Creating the CLI.
    cli.start();
    return 1;
}

// A function used for the multi-threading.
void *ClassificationServer::listenAndAcceptFunc(void *cc1) {
    ClassContainer cc = *((ClassContainer*)cc1);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_t thread1;
    ClientThread *lastTP;
    pthread_create(&thread1, &attr, ClassificationServer::listenFunc, &cc);
    while (true) {
        if (cc.getNT()->shouldStop()) {
            break;
        } else {
            if (cc.isListening() && *(cc.getNumAddress()) == 0) {
                if (lastTP != nullptr) {
                    lastTP->setWithCliet(true);
                }
                ClientThread *tp = cc.getTC()->getAvailableThread();
                lastTP = tp;
                *(cc.getNumAddress()) = 1;
                tp->runThread(ClassificationServer::startFunc, &cc);
            }
        }
    }
    pthread_cancel(lastTP->getMainThread());
    while (true) {
            cc.getTC()->joinAllClientThreads();
            break;
    }
    return nullptr;
}

// A function used for the multi-threading.
void *ClassificationServer::listenFunc(void *cc1) {
    ClassContainer* cc = (ClassContainer*)cc1;
    if (cc->getCS()->listenToSocket() < 0) { // Listening to socket.
        return nullptr;
    }
    cc->setListening(true);
    if (cc->getNT()->shouldStop()) {
        cc->setListening(false);
        std::terminate();
    }
    return nullptr;
}

// A constructor for a ClassificationServer.
ClassificationServer::ClassificationServer() : sizeBuffer(8192), server_port(40023), socketInt(socket(AF_INET,
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
        exit(1);
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

// A function that listens to a socket.
int ClassificationServer::listenToSocket() {
    if (listen(socketInt, 5) < 0) { // Listening to the socket.
        cout << "Error listening to a socket" << endl;
        return -1;
    }
    return 1;
}

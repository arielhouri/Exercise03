//
// Created by Ariel Houri on 8/6/2022.
//

#include "ClassificationServer.hpp"
#include <sstream>
#include "Commands/Command.hpp"
#include "Commands/AlgoSettingsCmd.hpp"
#include "Commands/ClassifyCmd.hpp"
#include "Commands/UploadCmd.hpp"
#include "Commands/DisplayResCmd.hpp"
#include "Commands/DownloadResCmd.hpp"
#include "Commands/ConfusionMatrixCmd.hpp"
#include "Commands/ExitCmd.hpp"
#include "SocketIO.h"
#include "CLI.hpp"
#include <cstring>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    ClassificationServer cs;
    // Should use Threading HERE!, when a client connects, starts a new thread with the start() method.
    if(cs.start() < 0) { // Starts the server, returns a negative value if there is an error.
        return -1;
    }
}

// A constructor for a ClassificationServer.
ClassificationServer::ClassificationServer() : sizeBuffer(4096), server_port(56789), socketInt(socket(AF_INET, SOCK_STREAM, 0)) {
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
        return;
    }
}

// A function that receives data from a given socket.
int ClassificationServer::receiveData(int clientSock) {
    int read_bytes = recv(clientSock, buffer, sizeBuffer, 0); // Receiving data from the Client.
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
    if (listenToSocket() < 0) { // Listening to socket.
        return -1;
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(socketInt, (struct sockaddr *) &client_sin, &addr_len);
    if (client_sock < 0) { // Checking for errors in the connection.
        cout << "Error accepting client" << endl;
        return -1;
    }
    SocketIO sio(8888); // What is this number??
    CLI cli(&sio); // Creating the CLI.


//    if (receiveData(client_sock) < 0) { // Receiving data from the Client's socket.
//        return -1;
//    }
//    string finalResult, irisString = this->convertToString(buffer);
//    int j = 0; // Classifying the irises and sending the results to the client:
//    while (irisString.length() != 0 && irisString.length() != 1) {
//        Classifiable i = stringToIris(irisString); // The Classifiable that we need to classify.
//        ClassifierKnn classifier(classifiableObjectsVector, i, k); // Creates the classifier for the iris i.
//        string result = classifier.classifierEuclidean(); // Gets the type of the Classifiable according to Euclidean metric.
//        int d = j;
//        for (j;
//             j < d + irisString.length() + 2; j++) { // Replaces the already-read data with a neutral character (^).
//            buffer[j] = '^';
//        }
//        finalResult += result; // Adds the type to the list of classified Irises.
//        finalResult += "\n";
//        irisString = convertToString(buffer); // Converts the next data of a Classifiable to a string.
//    }
//    char arr[finalResult.length() + 1]; // Creating the array that sends the data to the Client.
//    strcpy(arr, finalResult.c_str());
//    int sent_bytes = send(client_sock, arr, finalResult.length() + 1, 0); // Sending the type back to the client.
//    if (sent_bytes < 0) { // Checking for errors.
//        cout << "Error sending data to the client." << endl;
//        return -1;
//    }
}

// A function that listens to a socket.
int ClassificationServer::listenToSocket() {
    if (listen(socketInt, 5) < 0) { // Listening to the socket.
        cout << "Error listening to a socket" << endl;
        return -1;
    }
    return 1;
}


// A function that gets a pointer to a character and converts into a string, it ends when it reaches a '\n'.
string ClassificationServer::convertToString(char* txt) {
    string s;
    for (int i = 0; txt[i] != '\n'; i++) {
        if(txt[i] == '^') {
            continue;
        } else if(txt[i] == '\n' || txt[i] == '\r' || txt[i] == '\0') {
            break;
        }
        s += txt[i];
    }
    return s;
}

//
// Created by ariel on 8/6/2022.
//

#include "ClassificationServer.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include "ClassifierKnn.hpp"
#include <cstdio>
#include <cstring>

using namespace std;


int main(int argc, char *argv[]) {
    int k = 5; // The amount of elements that the classifier will use.
    ClassificationServer cs;
    vector<Iris> flowers = cs.setup(); // The creation of the database of classified flowers.
    struct sockaddr_in client_sin; // The connection between the server and the client.
    unsigned int addr_len = sizeof(client_sin);
    if (listen(cs.getSocketInt(), 5) < 0) { // Listening to the socket.
        cout << "Error listening to a socket" << endl;
        return -1;
    }
    int client_sock = accept(cs.getSocketInt(),  (struct sockaddr *) &client_sin,  &addr_len);
    if (client_sock < 0) { // Checking for errors in the connection.
        cout << "Error accepting client" << endl;
        return -1;
    }
    int read_bytes = recv(client_sock, cs.getBuffer(), cs.getSizeBuffer(), 0);
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
        return -1;
    }
    else if (read_bytes < 0) {
        cout << "Error reading input." << endl;
        return -1;
    }
    string irisString = cs.convertToString(cs.getBuffer());
    while(irisString.length() != 0 && irisString.length() != 1) { // Classifing the irises and sending the results to the client.
        Iris i = cs.stringToIris(irisString); // The Iris that we need to classify.
        ClassifierKnn classifier(flowers, i, k);
        string result = classifier.classifierEuclidean();
        char *arr = new char[result.length() + 1];
        strcpy(arr, result.c_str());
        int sent_bytes = send(client_sock, arr, result.length() + 1, 0); // Sending the type back to the client.
        if (sent_bytes < 0) {
            cout << "Error sending data to the client." << endl;
            return -1;
        }
        irisString = cs.convertToString(cs.getBuffer());
    }
    close(cs.getSocketInt());
    return 0;
}

// A constructor for a ClassificationServer.
ClassificationServer::ClassificationServer() {
    this->sizeBuffer = 2000;
    this->server_port = 6789;
    this->socketInt = socket(AF_INET, SOCK_STREAM, 0);
    if (socketInt < 0) {
        cout << "Error creating socket";
        return;
    }
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(socketInt, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error binding socket" << endl;
        return;
    }
}

// A getter for the buffer.
char* ClassificationServer::getBuffer() {
    return this->buffer;
};

// A getter for the socket.
int ClassificationServer::getSocketInt() const {
    return this->socketInt;
};

// A getter for the size of the buffer.
int ClassificationServer::getSizeBuffer() const {
    return this->sizeBuffer;
};

Iris ClassificationServer::stringToIris(string str) const {
    string type; // The type of the flower.
    double topLength; // The length of the top leafs.
    double topWidth; // The width of the top leafs.
    double bottomLength; // The length of the bottom leafs.
    double bottomWidth; // The width of the bottom leafs.
    string token;
    size_t pos = 0;
    string delimiter = ",";
    for(int i = 0; i < 4; i++) { // A loop that gathers the data about the flower from a sting.
        token = str.substr(0, pos);
        str.erase(0, pos + delimiter.length());
        switch (i + 1) {
            case 1:
                bottomWidth = stod(token);
                break;
            case 2:
                bottomLength = stod(token);
                break;
            case 3:
                topWidth = stod(token);
                break;
            case 4:
                topLength = stod(token);
                break;
            default:
                break;
        }
    }
    // The creation of the iris that we need to classify.
    Iris ir("Unclassified", topLength, topWidth, bottomLength, bottomWidth);
    return ir;
}

// A function that creates the database of classified irises.
vector<Iris> ClassificationServer::setup() {
    fstream fin;
    fin.open("../classified.csv", fstream::in); // Opens the classified-data file.
    string type; // The type of the flower.
    double topLength; // The length of the top leafs.
    double topWidth; // The width of the top leafs.
    double bottomLength; // The length of the bottom leafs.
    double bottomWidth; // The width of the bottom leafs.
    vector<Iris> flowers;
    string line;
    string word;
    while(getline(fin, line)){
        stringstream str(line);
        for(int i = 0; i < 5; i++) { // A loop that gathers the data about the iris from a sting.
            getline(str, word, ',');
            switch (i + 1) {
                case 5:
                    type = word;
                    break;
                case 1:
                    bottomWidth = stod(word);
                    break;
                case 2:
                    bottomLength = stod(word);
                    break;
                case 3:
                    topWidth = stod(word);
                    break;
                case 4:
                    topLength = stod(word);
                    break;
                default:
                    break;
            }
        }
        // The creation of the iris.
        Iris i(type, topLength, topWidth, bottomLength, bottomWidth);
        flowers.push_back(i);
    }
    fin.close();
    return flowers;
}

string ClassificationServer::convertToString(char* txt) {
    string s = "";
    for (int i = 0; txt[i] != '\n'; i++) {
        s = s + txt[i];
    }
    return s;
};
//
// Created by Ariel Houri on 8/6/2022.
//

#include "ClassificationServer.hpp"
#include <fstream>
#include <sstream>
#include "ClassifierKnn.hpp"
#include <cstring>

using namespace std;


int main() {
    int k = 7; // The amount of elements that the classifier will use.
    ClassificationServer cs;
    vector<Iris> flowers = cs.setup(); // The creation of the database of classified flowers.
    if(cs.run(flowers, k) < 0) { // Runs the program.
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
int ClassificationServer::run(vector<Iris> flowers, int k) {
    while(true) { // Infinite loop - when a client finishes, it waits for a new client.
        struct sockaddr_in client_sin; // The connection between the server and the client.
        unsigned int addr_len = sizeof(client_sin);
        if (listenToSocket() < 0) {
            return -1;
        }
        int client_sock = accept(socketInt, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) { // Checking for errors in the connection.
            cout << "Error accepting client" << endl;
            return -1;
        }
        if (receiveData(client_sock) < 0) { // Receiving data from the Client's socket.
            return -1;
        }
        string finalResult, irisString = this->convertToString(buffer);
        int j = 0; // Classifying the irises and sending the results to the client:
        while (irisString.length() != 0 && irisString.length() != 1) {
            Iris i = stringToIris(irisString); // The Iris that we need to classify.
            ClassifierKnn classifier(flowers, i, k); // Creates the classifier for the iris i.
            string result = classifier.classifierEuclidean(); // Gets the type of the Iris according to Euclidean metric.
            int d = j;
            for (j;
                 j < d + irisString.length() + 2; j++) { // Replaces the already-read data with a neutral character (^).
                buffer[j] = '^';
            }
            finalResult += result; // Adds the type to the list of classified Irises.
            finalResult += "\n";
            irisString = convertToString(buffer); // Converts the next data of an Iris to a string.
        }
        char arr[finalResult.length() + 1]; // Creating the array that sends the data to the Client.
        strcpy(arr, finalResult.c_str());
        int sent_bytes = send(client_sock, arr, finalResult.length() + 1, 0); // Sending the type back to the client.
        if (sent_bytes < 0) { // Checking for errors.
            cout << "Error sending data to the client." << endl;
            return -1;
        }
    }
}

// A function that listens to a socket.
int ClassificationServer::listenToSocket() {
    if (listen(socketInt, 5) < 0) { // Listening to the socket.
        cout << "Error listening to a socket" << endl;
        return -1;
    }
    return 1;
}

// A function that converts a string into an Iris object.
Iris ClassificationServer::stringToIris(string str) const {
    string type; // The type of the flower.
    double topLength; // The length of the top leafs.
    double topWidth; // The width of the top leafs.
    double bottomLength; // The length of the bottom leafs.
    double bottomWidth; // The width of the bottom leafs.
    string token;
    string delimiter = ",";
    size_t pos = str.find(delimiter);
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
        pos = str.find(delimiter);
    }
    // The creation of the iris that we need to classify.
    Iris ir("Unclassified", topLength, topWidth, bottomLength, bottomWidth);
    return ir;
}

// A function that creates the database of classified irises.
vector<Iris> ClassificationServer::setup() {
    fstream fin;
    fin.open("classified.csv", fstream::in); // Opens the classified-data file.
    string type; // The type of the flower.
    double topLength, topWidth, bottomLength, bottomWidth; // The length and width of the top and bottom leafs.
    vector<Iris> flowers;
    string line, word;
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

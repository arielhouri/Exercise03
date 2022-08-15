//
// Created by Yonatan Semidubersky on 12/08/2022.
//
// The client class read from unclassified irises-file
// and class them to output file (given as arguments to main).
#include "ClassificationClient.hpp"
#include <fstream>
#include <string>

using namespace std;
// reading from file in given path
string ClassificationClient::readingFromFile(string path){
    fstream fin;
    fin.open(path, fstream::in); // Opens the unclassified-irises file.
    string line, toServer;
    while(getline(fin, line)) { // Creates a string for the data.
        toServer += line;
        toServer += "\n";
    }
    fin.close();
    return toServer;
}

void ClassificationClient::communicateServer(string path, string path2){
    // connecting to a socket
    const char* ip_address = "127.0.0.1"; // The IP address that returns the sockets the same computer.
    const int port_no = 56789; // The port number.
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Creating the socket.
    if (sock < 0) {
        cout << "Error creating socket" << endl;
        return;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { // Connecting to the Server.
        cout << "Error connecting to the server" << endl;
        return;
    }
    string toServer = readingFromFile(path);
    // writing to file the output
    fstream fileout;
    fileout.open(path2, fstream::out | ofstream::trunc);
    char data_addr[toServer.length() + 1];
    strcpy(data_addr, toServer.c_str()); // Copies the data to an array.
    int data_len = strlen(data_addr);
    int sent_bytes = send(sock, data_addr, data_len, 0); // Sends the data to the Server.
    if (sent_bytes < 0) { // Checks for errors.
        cout << "Error sending data." << endl;
        return;
    }
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0); // Receiving data from the Server.
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
    }
    else if (read_bytes < 0) {
        cout << "Error reading input from the server!" << endl;
    }
    else { // Enters if no error occurred, prints the data to the file.
        fileout << buffer << endl;
    }
    close(sock);
    fileout.close();
}
int main(int argc, char* argv[]){
    string path = argv[argc - 2]; // The path for the unclassified data.
    string path2 = argv[argc - 1]; // The path for the destination for the data.
    ClassificationClient cc;
    cc.communicateServer(path,path2);
}

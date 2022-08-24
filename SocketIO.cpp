//
// Created by Yonatan Semidubersky on 25/08/2022.
//

#include "SocketIO.h"
#include <iostream>
#include <string>
using namespace std;
SocketIO::SocketIO(int port,char* id){
    this->port = port;
    this->id = id;
}
std::string SocketIO:: read() {
    const char* ip_address = this->id; // given id
    const int port_no = this->port; // The port number.
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Creating the socket.
    if (sock < 0) {
        cout << "Error creating socket" << endl;
        return "";
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { // Connecting to the Server.
        cout << "Error connecting to the server" << endl;
        close(sock);
        return "";
    }
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0); // Receiving data from the Server.
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
        close(sock);
        return "";
    }
    else if (read_bytes < 0) {
        cout << "Error reading input from the server!" << endl;
        close(sock);
        return "";
    }
    else { // Enters if no error occurred, return the data
        close(sock);
        return buffer;
    }
}
void SocketIO:: write(string toWrite){
    // connecting to a socket
    const char* ip_address = this->id;
    const int port_no = this->port; // The port number.
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
        close(sock);
        return;
    }
    char data_addr[toWrite.length() + 1];
    strcpy(data_addr, toWrite.c_str()); // Copies the data to an array.
    int data_len = strlen(data_addr);
    int sent_bytes = send(sock, data_addr, data_len, 0); // Sends the data to the Server.
    if (sent_bytes < 0) { // Checks for errors.
        cout << "Error sending data." << endl;
        close(sock);
        return;
    }
    close(sock);
}
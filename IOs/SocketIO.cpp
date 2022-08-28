//
// Created by Yonatan Semidubersky on 25/08/2022.
//

#include "SocketIO.h"
#include <iostream>
#include <string>
using namespace std;

SocketIO::SocketIO(int sock){
    this->sock = sock;
}

std::string SocketIO:: read() {
    char buffer[4096] = {0};
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->sock, buffer, expected_data_len, 0); // Receiving data from the Server.
    if (read_bytes == 0) {
        cout << "Connection is closed." << endl;
        close(this->sock);
        return "";
    }
    else if (read_bytes < 0) {
        cout << "Error reading input from the server!" << endl;
        return "";
    }
    else { // Enters if no error occurred, return the data
        return buffer;
    }
}

void SocketIO:: write(string toWrite){
    char data_addr[toWrite.length() + 1];
    strcpy(data_addr, toWrite.c_str()); // Copies the data to an array.
    int data_len = strlen(data_addr);
    int sent_bytes = send(this->sock, data_addr, data_len, 0); // Sends the data to the Server.
    if (sent_bytes < 0) { // Checks for errors.
        cout << "Error sending data." << endl;
        return;
    }
}
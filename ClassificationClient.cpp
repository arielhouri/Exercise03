//
// Created by Yonatan Semidubersky on 12/08/2022.
//

#include "ClassificationClient.hpp"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    // Connecting to the server socket
    const char* ip_address = "?.?.?.?";
    const int port_no = 6789;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket" << endl;
        return -1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error connecting to the server" << endl;
        return -1;
    }
    string path = argv[argc - 1];
    fstream fin;
    fin.open(path, fstream::in); // Opens the unclassified-irises file.
    fstream fileout;
    fileout.open("euclidean_output.csv", fstream::out | ofstream::trunc);
    string line;
    while(getline(fin, line)) {
        char data_addr[] = line;
        int data_len = strlen(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0);
        if (sent_bytes < 0) {
            // error
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            // connection is closed
        }
        else if (read_bytes < 0) {
            // error
        }
        else {
            fileout << buffer << endl;
        }
    }
    close(sock);
    fin.close();
    fileout.close();
}

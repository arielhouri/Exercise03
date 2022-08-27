//
// Created by Yonatan Semidubersky on 12/08/2022.
//
// The client class read from unclassified-objects file
// and classify them to an output file (given as arguments to main).
#include "ClassificationClient.hpp"
#include <fstream>
#include <string>

using namespace std;
    // reading from file in given path
    string ClassificationClient::readingFromFile(const string& path){
        fstream fin;
        fin.open(path, fstream::in); // Opens the file.
        string line, toServer;
        while(getline(fin, line)) { // Creates a string for the data.
            toServer += line;
            toServer += "\n";
        }
        fin.close();
        return toServer;
    }
    string ClassificationClient::read(int sock) {
        // if there is problem with communication - printing the error and exit.
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0); // Receiving data from the Server.
        if (read_bytes == 0) {
            cout << "Connection is closed." << endl;
            close(sock);
            exit(1);
        }
        else if (read_bytes < 0) {
            cout << "Error reading input from the server!" << endl;
            close(sock);
            exit(1);
        }
        else { // Enters if no error occurred, return the data
            return buffer;
        }
    }
    void ClassificationClient::write(int sock, const string& toWrite) {
        // if there is problem with communication - printing the error and exit.
        char data_addr[toWrite.length() + 1];
        strcpy(data_addr, toWrite.c_str()); // Copies the data to an array.
        int data_len = strlen(data_addr);
        int sent_bytes = send(sock, data_addr, data_len, 0); // Sends the data to the Server.
        if (sent_bytes < 0) { // Checks for errors.
            cout << "Error sending data." << endl;
            close(sock);
            exit(1);
        }
    }
    void ClassificationClient::communicateServer() {
        // connecting to a socket
        const char *ip_address = "127.0.0.1"; // The IP address that returns the sockets the same computer.
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
        string messageCommand; // "$command$"
        string message; // message after command
        char buffer[4096]; // reading from server
        int num; // choosing an option
        string toServer; // send to server
        string pathReadFrom; // for upload a file
        string pathToWrite; // for download a file
        bool shouldStop = false;
        while (!shouldStop){
            messageCommand = read(sock);
            // in order to support working with files,
            // input and output - The server send 2 messages each time,
            // the first is instruction.
            // classify the command:
            if (messageCommand == "$exit$"){
                shouldStop = true;
                continue;
            }
            message = read(sock);
            if (messageCommand == "$print$"){
                cout << message << endl;
            }
            // choosing an option.
            if (messageCommand == "$print&Num$"){
                cout << message << endl;
                cin >> num;
                write(sock, to_string(num));
            }
            // upload local file (command 1)
            if (messageCommand == "$print&upload$"){
                cout << message << endl;
                cin >> pathReadFrom;
                write(sock,readingFromFile(pathReadFrom));
            }
            // changing the parameter (command 2)
            if (messageCommand == "$print&giveNewArgs$"){
                cout << message << endl;
                cin >> toServer;
                write(sock, toServer);
            }
            // download a file (command 5)
            if (messageCommand == "$print&download$"){
                cout << message << endl;
                cin >> pathToWrite;
                fstream fileout;
                fileout.open(pathToWrite, fstream::out | ofstream::trunc);
                fileout << buffer << endl;
                fileout.close();
            }
        }
        close(sock);
    }
    int main(int argc, char *argv[]) {
        string path = argv[argc - 2]; // The path for the unclassified data.
        string path2 = argv[argc - 1]; // The path for the destination for the data.
        ClassificationClient cc;
        cc.communicateServer();
    }
//
// Created by Yonatan Semidubersky on 12/08/2022.
//
// The client class read from unclassified-objects file
// and classify them to an output file (given as arguments to main).
#include "ClassificationClient.hpp"
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>

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
        std::fill(buffer, buffer + 4096, 0);
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

    string ClassificationClient::commandSplit(string message){
        string dollar = "$";
        size_t pos = 0;
        message.erase(0, pos + dollar.length());
        pos = message.find(dollar);
        string token = message.substr(0, pos);
        return "$" + token + "$";
    }

    string ClassificationClient::messageSplit(string message){
        string dollar = "$";
        size_t pos = 0;
        string token;
        message.erase(0, pos + dollar.length());
        pos = message.find(dollar);
        message.erase(0, pos + dollar.length());
        return message;
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
        const int port_no = 40690; // The port number.
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
        int num; // choosing an option
        string toServer; // send to server
        string pathReadFrom; // for upload a file
        string pathToWrite; // for download a file
        bool shouldStop = false;
        while (!shouldStop){
            message = read(sock);
            // in order to support working with files,
            // input and output - The server send 2 messages each time,
            // the first is instruction.
            messageCommand = commandSplit(message);
            message = messageSplit(message);
            // classify the command:
            if (messageCommand == "$exit$"){
                shouldStop = true;
                continue;
            }
            if (messageCommand == "$print$"){
                cout << message << endl;
                write(sock, "$sent$");
            }
            // choosing an option.
            if (messageCommand == "$print&num$"){
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
            if (messageCommand == "$print&string$"){
                cout << message << endl;
                cin >> toServer;
                write(sock, toServer);
            }
            // download a file (command 5)
            if (messageCommand == "$print&download$"){
                cout << message << endl;
                write(sock, "$sent$");
                cin >> pathToWrite;
                fstream fileout;
                fileout.open(pathToWrite, fstream::out | ofstream::trunc);
                fileout.close();
            }
        }
        close(sock);
    }

    int main() {
        ClassificationClient cc;
        cc.communicateServer();
    }
//
// Created by Yonatan Semidubersky on 8/16/2022.
//
#include <string>
#include <iostream>
#include "Commands/Command.hpp"
#include "Commands/ClassifyCmd.hpp"
#include "Commands/AlgoSettingsCmd.hpp"
#include "Commands/DisplayResCmd.hpp"
#include "Commands/DownloadResCmd.hpp"
#include "Classifier/ClassifierParameters.hpp"
#include "CLI.hpp"
#include "Commands/UploadCmd.hpp"
#include "Commands/ConfusionMatrixCmd.hpp"
#include "Commands/ExitCmd.hpp"

// A constructor for the CLI.
CLI::CLI(DefaultIO* sio){
    this->shouldStop = false;
    ClassifierParameters* cp = new ClassifierParameters();
    this->sio = sio;
    Command** pCommands = new Command*[7];
    pCommands[0] = new UploadCmd(classifiedData, unclassifiedData, sio);
    pCommands[1] = new AlgoSettingsCmd(*cp, sio); // algorithm settings
    pCommands[2] = new ClassifyCmd(results, classifiedData, unclassifiedData, *cp, sio); // classify data
    pCommands[3] = new DisplayResCmd(results, sio);// display Results
    pCommands[4] = new DownloadResCmd(results, sio); // download results
    pCommands[5] = new ConfusionMatrixCmd(classifiedData, unclassifiedData, *cp, sio);// display Results
    pCommands[6] = new ExitCmd(sio); // download results
    this->commands = pCommands;
}

// Initializing the CLI and starting the communication.
void CLI::start() {
    int commandPick;
    // menu to print
    string menu = "";
    for (int i = 0; i < 7; i++){
        menu += (to_string(i+1) + ". " +(this->commands)[i]->getDescription());
        if (i == 6) {
            break;
        }
        menu += "\n";
    }
    while(!shouldStop){
        // printing the menu
        (this->sio)->write("$print&num$" + menu); // print and read option to Choose
        string str = (this->sio)->read();
        std::cout << str << std::endl;
        commandPick = stoi(str);
        commands[commandPick - 1]->execute();
    }
    delete(this->commands);
}
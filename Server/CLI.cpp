//
// Created by Yonatan Semidubersky on 8/16/2022.
//
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
    ClassifierParameters cp;
    this->sio = sio;
    // Creating the actual commands-objects.
    UploadCmd cmd1(classifiedData, unclassifiedData, sio);
    AlgoSettingsCmd cmd2(cp, sio);
    ClassifyCmd cmd3(results, classifiedData, unclassifiedData, cp, sio);
    DisplayResCmd cmd4(results, sio);
    DownloadResCmd cmd5(results, sio);
    ConfusionMatrixCmd cmd6(classifiedData, unclassifiedData, cp, sio);
    ExitCmd cmd7(sio);
    this->commands[0] = &cmd1; // Creating the commands-array:
    this->commands[1] = &cmd2;
    this->commands[2] = &cmd3;
    this->commands[3] = &cmd4;
    this->commands[4] = &cmd5;
    this->commands[5] = &cmd6;
    this->commands[6] = &cmd7;

}

// Initializing the CLI and starting the communication.
void CLI::start() {
    int commandPick;
    // menu to print
    string menu = "";
    for (int i = 0; i < 7; i++){
        menu += (to_string(i+1) + ". " +(this->commands)[i]->getDescription());
    }
    while(!this->shouldStop){
        // printing the menu
        (this->sio)->write("$print&num$"); // print and read option to Choose
        (this->sio)->write(menu);
        commandPick = stoi((this->sio)->read());
        if (commandPick < 1 || commandPick > 8){
            this->sio->write("$print$");
            this->sio->write("invalid input");
            continue;
        }
        commands[commandPick - 1]->execute();
    }
    delete(this->commands);
}
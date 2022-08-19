//
// Created by Yonatan Semidubersky on 8/16/2022.
//
#include "Commands/Command.hpp"
#include "Commands/ClassifyCmd.hpp"
#include "Commands/AlgoSettingsCmd.hpp"
#include "Commands/DisplayResCmd.hpp"
#include "Commands/DownloadResCmd.hpp"
#include "ClassifierParameters.hpp"
#include "CLI.hpp"

CLI::CLI(DefaultIO io){
    // initialize the fields (empty string stands for uninitialized field)
    this->pathFile = "";
    this->parameters = ClassifierParameters();
    this-> results = "";
    this-> shouldStop = false;
    this->io = &io;
    Command** pCommands = new Command*[7];
    pCommands[0] = // upload an unclassified csv data file
    pCommands[1] = new AlgoSettingsCmd(this->parameters,this->io); // algorithm settings
    commands[2] = new ClassifyCmd(this->pathFile, this->parameters, this->io); // classify data
    commands[3] = new DisplayResCmd(this->results, this->io);// display Results
    commands[4] = new DownloadResCmd(this->results, this->pathFile); // download results
    // Waiting for finish of the Commands...
    this->commands = pCommands;
}
void CLI::start() {
    int commandChoose;
    while(!this->shouldStop){
        // printing the menu
        for (int i = 0; i < 7; i++){
            (this->io)->write((this->commands)[i]->getDescription());
        }
        commandChoose = stoi((this->io)->read());
        if (commandChoose < 1 || commandChoose > 8){
            this->io->write("invalid input");
            continue;
        }
        commands[commandChoose - 1]->execute();
    }
}
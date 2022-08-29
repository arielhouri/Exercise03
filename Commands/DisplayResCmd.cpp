//
// Created by Ariel Houri on 8/18/2022.
//

#include "Commands/DisplayResCmd.hpp"

// A constructor for the Display-Results-Command.
DisplayResCmd::DisplayResCmd(ClassificationFiles* files, DefaultIO* dio){
    this->files = files;
    this->description = "display results";
    this->dio = dio;
}

void DisplayResCmd::execute() {
    dio->write("$print$" + this->files->getResults());
    dio->read();
    dio->write("$print$Done.");
    dio->read();
}
//
// Created by Ariel Houri on 8/18/2022.
//

#include "DisplayResCmd.hpp"

// A constructor for the Display-Results-Command.
DisplayResCmd::DisplayResCmd(ClassificationFiles* files, DefaultIO* dio){
    this->files = files;
    this->description = "display results";
    this->dio = dio;
}

void DisplayResCmd::execute() {
    if (this->files->getResults() == ""){
        this->dio->write("$print$please upload files and classify.");
        this->dio->read();
        return;
    }
    dio->write("$print$" + this->files->getResults()); // Prints the results to the client.
    dio->read(); // Used for the flow of the program, no use to the value recieved.
    dio->write("$print&enter$Done."); // Prints that the process finished and waiting for enter.
    dio->read(); // Used for the flow of the program, no use to the value recieved.
}
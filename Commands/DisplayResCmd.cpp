//
// Created by Ariel Houri on 8/18/2022.
//

#include <fstream>
#include "Commands/DisplayResCmd.hpp"

// A constructor for the Display-Results-Command.
DisplayResCmd::DisplayResCmd(std::string* resultsPath, DefaultIO* dio) {
    this->description = "display results";
    this->dio = dio;
    this->resultsPath = resultsPath;
}

void DisplayResCmd::execute() {
    std::fstream fin; // Opens the results file.
    fin.open(*this->resultsPath, std::fstream::in);
    std::string line;
    while(getline(fin, line)){ // Loop over all the lines of the results file.
        this->dio->write(line); // Prints the lines.
    }
    fin.close(); // Closes the results file-stream.
    this->dio->write("Done.");
}
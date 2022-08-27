//
// Created by Ariel Houri on 8/18/2022.
//

#include <fstream>
#include "Commands/DisplayResCmd.hpp"

// A constructor for the Display-Results-Command.
DisplayResCmd::DisplayResCmd(std::string& results, DefaultIO* dio) : results(results) {
    this->description = "display results";
    this->dio = dio;
}

void DisplayResCmd::execute() {
    dio->write("$print$");
    this->dio->write(results);
    dio->write("$print$");
    this->dio->write("Done.");
}
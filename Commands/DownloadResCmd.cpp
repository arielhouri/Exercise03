//
// Created by ariel on 8/18/2022.
//

#include <fstream>
#include "Commands/DownloadResCmd.hpp"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(std::string& results, DefaultIO* dio) : results(results){
    this->description = "download results";
    this->dio = dio;
}

void DownloadResCmd::execute() {
    dio->write("$print&download$\n");
    dio->write(results);
    dio->write("$print$\n");
    dio->write("Done.\n");
}
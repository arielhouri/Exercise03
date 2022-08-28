//
// Created by ariel on 8/18/2022.
//

#include "Commands/DownloadResCmd.hpp"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(std::string& results, DefaultIO* dio) : results(results){
    this->description = "download results";
    this->dio = dio;
}

void DownloadResCmd::execute() {
    dio->write("$print&download$");
    dio->write(results);
    dio->write("$print$");
    dio->write("Done.");
}
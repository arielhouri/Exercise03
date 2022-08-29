//
// Created by ariel on 8/18/2022.
//

#include "Commands/DownloadResCmd.hpp"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(ClassificationFiles* files, DefaultIO* dio){
    this->files = files;
    this->description = "download results";
    this->dio = dio;
}

void DownloadResCmd::execute() {
    dio->write("$print&download$" + this->files->getResults());
    dio->read();
    dio->write("$print$Done.");
    dio->read();
}
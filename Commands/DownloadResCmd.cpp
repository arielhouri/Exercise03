//
// Created by ariel on 8/18/2022.
//

#include "Commands/DownloadResCmd.hpp"
#include "Server/ClassificationFiles.h"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(ClassificationFiles* files, DefaultIO* dio){
    this->files = files;
    this->description = "download results";
    this->dio = dio;
}

void DownloadResCmd::execute() {
    dio->write("$print$Please download the csv file.");
    dio->read();
    dio->write("$download$" + this->files->getResults());
    dio->read();
    dio->write("$print$Done.");
    dio->read();
}
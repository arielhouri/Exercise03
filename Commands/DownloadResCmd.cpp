//
// Created by ariel on 8/18/2022.
//

#include "DownloadResCmd.hpp"
#include "../Server/ClassificationFiles.hpp"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(ClassificationFiles* files, DefaultIO* dio){
    this->files = files;
    this->description = "download results";
    this->dio = dio;
}

void DownloadResCmd::execute() {
    if (this->files->getResults() == ""){
        this->dio->write("$print$please upload files and classify.");
        return;
    }
    dio->write("$print$Please download the csv file.");
    dio->read();
    dio->write("$download$" + this->files->getResults());
    dio->read();
    dio->write("$print$Done.");
    dio->read();
}
//
// Created by Ariel Houri on 8/20/2022.
//

#include "UploadCmd.hpp"
#include "../Server/ClassificationFiles.hpp"
#include <iostream>
UploadCmd::UploadCmd(ClassificationFiles* files, DefaultIO* dio) {
    this->files = files;
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
}

void UploadCmd::execute() {
    std::string inputStr;
    dio->write("$print&upload$Please upload your local train csv file.");
    inputStr = dio->read(); // Gets the classified objects file.
    this->files->setClassified(inputStr); // Saves the classified-data in a variable.
    dio->write("$print$Upload complete."); // Notifies that the first part of the upload is over.
    dio -> read();
    dio->write("$print&upload$Please upload your local test csv file.");
    inputStr = dio->read(); // Gets the unclassified objects file.
    this->files->setUnClassified(inputStr); // Saves unclassified-data in a variable.
    dio->write("$print$Upload complete."); // Notifies that the whole upload is over.
    dio->read();
}

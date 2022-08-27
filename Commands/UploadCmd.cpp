//
// Created by Ariel Houri on 8/20/2022.
//

#include "UploadCmd.hpp"

UploadCmd::UploadCmd(std::string& classifiedData, std::string& unclassifiedData, DefaultIO* dio) :
        classifiedData(classifiedData), unclassifiedData(unclassifiedData) {
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
}

void UploadCmd::execute() {
    std::string inputStr;
    dio->write("$print&upload$\n");
    dio->write("Please upload your local train csv file.\n");
    inputStr = dio->read(); // Gets the classified objects file.
    classifiedData = inputStr; // Saves the classified-data in a variable.
    dio->write("$print$\n");
    dio->write("Upload complete.\n"); // Notifies that the first part of the upload is over.
    dio->write("$print&upload\n");
    dio->write("Please upload your local test csv file.\n");
    inputStr = dio->read(); // Gets the unclassified objects file.
    this->unclassifiedData = inputStr; // Saves unclassified-data in a variable.
    dio->write("$print$\n");
    dio->write("Upload complete.\n"); // Notifies that the whole upload is over.
}

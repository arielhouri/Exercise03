//
// Created by ariel on 8/20/2022.
//

#include "UploadCmd.hpp"

UploadCmd::UploadCmd(std::string& classifiedData, std::string& unclassifiedData, DefaultIO* dio) :
classifiedData(classifiedData),unclassifiedData(unclassifiedData) {
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
}

void UploadCmd::execute() {
    std::string inputStr;
    dio->write("Please upload your local train csv file.");
    inputStr = dio->read(); // Gets the classified objects file.
    classifiedData = inputStr; // Saves the address in a variable.
    dio->write("Upload complete."); // Notifies that the first part of the upload is over.
    dio->write("Please upload your local test csv file.");
    inputStr = dio->read(); // Gets the unclassified objects file.
    unclassifiedData = inputStr; // Saves the address in a variable.
    dio->write("Upload complete."); // Notifies that the whole upload is over.
}

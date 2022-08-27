//
// Created by Ariel Houri on 8/20/2022.
//

#include "UploadCmd.hpp"

UploadCmd::UploadCmd(std::string& classifiedData, std::string& unclassifiedData, DefaultIO* dio) :
        classifiedDataAddress(classifiedData), unclassifiedDataAddress(unclassifiedData) {
    this->dio = dio;
    this->description = "upload an unclassified csv data file";
}

void UploadCmd::execute() {
    std::string inputStr;
    dio->write("Please upload your local train csv file.");
    inputStr = dio->read(); // Gets the classified objects file.
    classifiedDataAddress = inputStr; // Saves the address in a variable.
    dio->write("Upload complete."); // Notifies that the first part of the upload is over.
    dio->write("Please upload your local test csv file.");
    inputStr = dio->read(); // Gets the unclassified objects file.
    this->unclassifiedDataAddress = inputStr; // Saves the address in a variable.
    dio->write("Upload complete."); // Notifies that the whole upload is over.
}

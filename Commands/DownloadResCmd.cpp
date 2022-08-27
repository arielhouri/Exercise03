//
// Created by ariel on 8/18/2022.
//

#include <fstream>
#include "Commands/DownloadResCmd.hpp"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(std::string& outputPath, std::string& results, DefaultIO* dio) : results(results),
                                                                                                printPath(outputPath){
    this->description = "download results";
    this->dio = dio;
}

void DownloadResCmd::execute() {
    dio->writeToFile(printPath,results);
    dio->writeToFile(printPath, "Done.");
}
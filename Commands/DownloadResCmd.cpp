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
    std::fstream fout; // Opens the output file.
    if (printPath.empty()) {
        this->dio->write("Error!");
        return;
    }
    fout.open(this->printPath, std::fstream::out | std::fstream::trunc);
    fout << results << std::endl << "Done." << std::endl; // Prints the results.
    fout.close(); // Closes the output file-stream.
}
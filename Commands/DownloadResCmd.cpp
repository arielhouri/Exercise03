//
// Created by ariel on 8/18/2022.
//

#include <fstream>
#include "Commands/DownloadResCmd.hpp"

// A constructor for DownloadResCmd Command.
DownloadResCmd::DownloadResCmd(std::string& outputPath, std::string& resPath, DefaultIO* dio) : resPath(resPath),
                                                                                                printPath(outputPath){
    this->dio = dio;
}

void DownloadResCmd::execute() {
    std::fstream fin; // Opens the results file.
    if (resPath.empty()) {
        this->dio->write("Error!");
        return;
    }
    fin.open(this->resPath, std::fstream::in);
    std::fstream fout; // Opens the output file.
    if (printPath.empty()) {
        this->dio->write("Error!");
        return;
    }
    fin.open(this->printPath, std::fstream::out | std::fstream::trunc);
    std::string line;
    while(getline(fin, line)){ // Loop over all the lines of the results file.
        fout << line << std::endl;
    }
    fout << "Done." << std::endl;
    fin.close(); // Closes the results file-stream.
    fout.close(); // Closes the output file-stream.
} // Need to add a part!!!!
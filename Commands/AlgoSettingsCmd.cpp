//
// Created by Ariel Houri on 8/17/2022.
//

#include "AlgoSettingsCmd.hpp"

void AlgoSettingsCmd::execute() {
    std::string msg = "The current KNN parameters are: K = "; // Building the msg.
    msg += std::to_string(classParams.getK());
    msg += ", distance metric = ";
    msg += classParams.getMetric();
    dio->write(msg); // Printing the algorithm's settings.
    std::string ans = dio->read();
    if (ans.empty() || ans == "\n") { // Checking if the user wants to change the settings.
        return;
    }
    size_t pos = ans.find(' '); // Cutting their answer to the new K and the new metric.
    std::string token = ans.substr(0, pos);
    ans.erase(0, pos + 1);
    if (classParams.setK(stoi(token)) != 0 && classParams.setMetric(ans) != 0) {
        dio->write("Both arguments are invalid!");
        return;
    }
    if (classParams.setK(stoi(token)) != 0) { // Setting the new value of K.
        dio->write("Invalid value of K, The new metric was set.");
        return;
    }
    if (classParams.setMetric(ans) != 0) { // Setting the new Metric.
        dio->write("Invalid metric, The new value of K was set.");
        return;
    }
    dio->write("The new values were set.");
}

AlgoSettingsCmd::AlgoSettingsCmd(ClassifierParameters& newCP, DefaultIO* dio) : classParams(newCP) {
    this->dio = dio;
    this->description = "algorithm settings";
}
//
// Created by Ariel Houri on 8/17/2022.
//

#include <iostream>
#include "AlgoSettingsCmd.hpp"

void AlgoSettingsCmd::execute() {
    std::string msg = classParams.getStringRepresentation();
    dio->write("$print&string$" + msg);
    std::string ans = dio->read();
    if (ans == "$empty$") { // Checking if the user wants to change the settings.
        return;
    }
    size_t pos = ans.find(' '); // Cutting their answer to the new K and the new metric.
    std::string token = ans.substr(0, pos);
    ans.erase(0, pos + 1);
    std::cout << "Token:" << token << std::endl;
    std::cout << "metric:" << ans << ans.length() << std::endl;
    if (classParams.setK(stoi(token)) != 1 && classParams.setMetric(ans) != 1) {
        dio->write("$print$Both arguments are invalid!");
        return;
    }
    if (classParams.setK(stoi(token)) != 1) { // Setting the new value of K.
        dio->write("$print$Invalid value of K, The new metric was set.");
        return;
    }
    if (classParams.setMetric(ans) != 1) { // Setting the new Metric.
        dio->write("$print$Invalid metric, The new value of K was set.");
        return;
    }
    dio->write("$print$The new values were set.");
}

AlgoSettingsCmd::AlgoSettingsCmd(ClassifierParameters& newCP, DefaultIO* dio) : classParams(newCP) {
    this->dio = dio;
    this->description = "algorithm settings";
}
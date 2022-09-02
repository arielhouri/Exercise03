//
// Created by Ariel Houri on 8/17/2022.
//

#include <iostream>
#include "AlgoSettingsCmd.hpp"

void AlgoSettingsCmd::execute() {
    int finished = 1;
    std::string msg = classParams->getStringRepresentation();
    dio->write("$print&string$" + msg);
    std::string ans = dio->read();
    if (ans == "$empty$") { // Checking if the user wants to change the settings.
        return;
    }
    size_t pos = ans.find(' '); // Cutting their answer to the new K and the new metric.
    std::string token = ans.substr(0, pos);
    ans.erase(0, pos + 1);
    while (finished != 0) { // NOT WORKING, not receiving the first char!
        if (!isNumber(token)) {
            dio->write("$print&string$You must enter a number for K! Please enter new arguments:");
            ans = dio->read();
            pos = ans.find(' '); // Cutting their answer to the new K and the new metric.
            token = ans.substr(0, pos);
            ans.erase(0, pos + 1);
            continue;
        }
        if (classParams->setK(stoi(token)) != 1 && classParams->setMetric(ans) != 1) {
            dio->write("$print&string$Both arguments are invalid! Please enter new arguments:");
            ans = dio->read();
            pos = ans.find(' '); // Cutting client's answer to the new K and the new metric.
            token = ans.substr(0, pos);
            ans.erase(0, pos + 1);
            continue;
        }
        if (classParams->setK(stoi(token)) != 1) { // Setting the new value of K.
            dio->write("$print&string$Invalid value of K, The new metric was set. Please enter new value for K:");
            std::string str = dio->read();
            if (isNumber(str)) {
                token = std::to_string(stoi(str));
            }
            continue;
        }
        if (classParams->setMetric(ans) != 1) { // Setting the new Metric.
            dio->write("$print&string$Invalid metric, The new value of K was set. Please enter a new Metric:");
            ans = dio->read();
            continue;
        }
        finished = 0;
    }
    dio->write("$print$The new values were set.");
    dio->read();
}

AlgoSettingsCmd::AlgoSettingsCmd(ClassifierParameters* newCP, DefaultIO* dio) : classParams(newCP) {
    this->dio = dio;
    this->description = "algorithm settings";
}

bool AlgoSettingsCmd::isNumber(std::string s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
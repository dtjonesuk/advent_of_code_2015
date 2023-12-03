//
// Created by David on 03/12/2023.
//

#include "Command.h"

Command::Command(const std::string &line) {
    std::stringstream ss(line);

    std::string command1, command2, through;
    int x1, y1, x2, y2;
    char comma;

    // parse the command
    ss >> command1;
    if (command1 == "turn") {
        ss >> command2;
        if (command2 == "on") {
            cmd = turn_on;
        } else {
            cmd = turn_off;
        }
    } else {
        cmd = toggle;
    }

    // parse the co-ordinates
    ss >> x1 >> comma >> y1 >> through >> x2 >> comma >> y2;

    from = {x1, y1};
    to = {x2, y2};
}

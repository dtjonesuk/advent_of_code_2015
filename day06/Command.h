//
// Created by David on 03/12/2023.
//

#ifndef INC_2015_COMMAND_H
#define INC_2015_COMMAND_H

#include <string>
#include <sstream>
#include <utility>

namespace day06 {
    enum command_t {
        toggle,
        turn_on,
        turn_off
    };

    struct Command {
        Command(const std::string &line);

        command_t cmd;
        std::pair<int, int> from;
        std::pair<int, int> to;

    };
}

#endif //INC_2015_COMMAND_H

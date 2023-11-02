//
// Created by David on 02/11/2023.
//

#include "Reindeer.h"
#include <regex>
#include <iostream>

const static std::string reindeerExpression = "([A-Z]\\w+) can fly (\\d+) km/s for (\\d+) seconds, but then must rest for (\\d+) seconds.";

Reindeer::Reindeer(const std::string &s) {
    std::regex re(reindeerExpression);
    std::smatch match;
    if (std::regex_search(s, match, re)) {
        name = match.str(1);
        speed = stoi(match.str(2));
        flyTime = stoi(match.str(3));
        restTime = stoi(match.str(4));
    }
}

// simulate one second
void Reindeer::Tick() {
    // increment t
    ++t;

    if (t <= flyTime) {
        // std::cout << name << " is flying " << speed << " km. (" << t << ")" << std::endl;
        distance += speed;
    } else {
        // std::cout << name << " is resting. (" << t << ")" << std::endl;
    }

    // wrap around if necessary
    if (t >= (flyTime + restTime))
        t = 0;
}

int Reindeer::getDistance() const {
    return distance;
}

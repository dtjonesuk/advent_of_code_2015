//
// Created by David on 03/12/2023.
//

#include "Santa.h"

Santa::Santa(LocationMap &l) : locations(l) {}

void Santa::move(char ch) {
    // move current location 1 square (based on ch), then add a present at new location
    switch (ch) {
        case '^':
            currentLocation.second += 1;
            locations[currentLocation] += 1;
            break;
        case '>':
            currentLocation.first += 1;
            locations[currentLocation] += 1;
            break;
        case 'v':
            currentLocation.second -= 1;
            locations[currentLocation] += 1;
            break;
        case '<':
            currentLocation.first -= 1;
            locations[currentLocation] += 1;
            break;
        default:
            throw std::runtime_error("Invalid input!");
    }
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <vector>
#include <functional>
#include <numeric>

constexpr int size_x = 1000;
constexpr int size_y = 1000;
constexpr int index(int x, int y) { return y * size_y + x; }

enum command_t {
    toggle,
    turn_on,
    turn_off
};

void partOne() {
    std::ifstream input("..\\day06\\input.txt");

    std::vector<bool> lights(size_x * size_y, false);

    std::string line;
    int total = 0;

    while (std::getline(input, line)) {
        std::stringstream ss(line);

        std::string command1, command2, through;
        command_t command;

        int x1, y1, x2, y2;
        char comma;

        // parse the command
        ss >> command1;
        if (command1 == "turn") {
            ss >> command2;
            if (command2 == "on") {
                command = turn_on;
            } else {
                command = turn_off;
            }
        } else {
            command = toggle;
        }

        // parse the co-ordinates
        ss >> x1 >> comma >> y1 >> through >> x2 >> comma >> y2;

        // operate on the block of lights
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                switch (command) {
                    case turn_on:
                        lights[index(x,y)] = true;
                        break;
                    case turn_off:
                        lights[index(x,y)] = false;
                        break;
                    case toggle:
                        lights[index(x, y)] = !lights[index(x, y)];
                        break;
                    default:
                        std::cerr << "Invalid command!" << std::endl;
                        exit(1);
                        break;
                }
            }
        }

        //std::cout << command << " (" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")" << std::endl;
    }

    // calculate how many lights are on
    total = std::count(lights.begin(), lights.end(), true);

    std::cout << "Part One: lights on = " << total << std::endl;

}

void partTwo() {
    std::ifstream input("..\\day06\\input.txt");

    std::vector<int> lights(size_x * size_y, 0);

    std::string line;
    int total = 0;

    while (std::getline(input, line)) {
        std::stringstream ss(line);

        std::string command1, command2, through;
        command_t command;

        int x1, y1, x2, y2;
        char comma;

        // parse the command
        ss >> command1;
        if (command1 == "turn") {
            ss >> command2;
            if (command2 == "on") {
                command = turn_on;
            } else {
                command = turn_off;
            }
        } else {
            command = toggle;
        }

        // parse the co-ordinates
        ss >> x1 >> comma >> y1 >> through >> x2 >> comma >> y2;

        // operate on the block of lights
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                switch (command) {
                    case turn_on:
                        lights[index(x,y)] += 1;
                        break;
                    case turn_off:
                        lights[index(x,y)] = std::max(lights[index(x,y)] - 1, 0);
                        break;
                    case toggle:
                        lights[index(x, y)] += 2;
                        break;
                    default:
                        std::cerr << "Invalid command!" << std::endl;
                        exit(1);
                        break;
                }
            }
        }

        //std::cout << command << " (" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ")" << std::endl;
    }

    // calculate how many lights are on
    //total = std::count_if(lights.begin(), lights.end(), [](bool b) { return b; });
    total = std::accumulate(lights.begin(), lights.end(), 0);

    std::cout << "Part Two: total brightness = " << total << std::endl;
}


int main() {

    partOne();
    partTwo();
}
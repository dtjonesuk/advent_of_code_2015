#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <regex>

// user specific puzzle input
const int input = 29'000'000;

void partOne() {
    constexpr auto calc_presents = [](int elf) {
        return 10 * elf;
    };

    int house = 0;
    int presents = 0;
    do {
        ++house;
        presents = 0;

        // get factors up to square root of house, then calc the corresponding factor = house /elf
        for (int elf = int(std::sqrt(house)); elf > 0; --elf) {
            if (house % elf == 0) {
                presents += calc_presents(elf);
                presents += calc_presents(house / elf);
            }
        }
    } while (presents < input);


    std::cout << "Day 20: Part One=" << house << std::endl;
}

void partTwo() {
    int house = 0;
    int presents = 0;

    constexpr auto calc_presents = [](int house, int elf) {
        if (house <= (elf * 50)) {
            return 11 * elf;
        }
        return 0;
    };

    do {
        ++house;
        presents = 0;

        // get factors up to square root of house, then calc the corresponding factor = house /elf
        for (int elf = int(std::sqrt(house)); elf > 0; --elf) {
            if (house % elf == 0) {
                presents += calc_presents(house, elf);
                presents += calc_presents(house, house / elf);
            }
        }
        //std::cout << "House " << house << " got " << presents << " presents." << std::endl;

    } while (presents < input);


    std::cout << "Day 20: Part Two=" << house << std::endl;
}

int main() {
    partOne();
    partTwo();

    return 0;
}
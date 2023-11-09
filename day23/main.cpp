#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "Computer.h"

void partOne() {
    std::ifstream input("..\\day23\\input.txt");
    Computer computer(input);

    computer.run();

    std::cout << "Day 23: Part One = " << computer.reg_b << std::endl;
}

void partTwo() {
    std::ifstream input("..\\day23\\input.txt");
    Computer computer(input);
    computer.reg_a = 1;
    computer.run();

    std::cout << "Day 23: Part Two = " << computer.reg_b << std::endl;
}

int main() {
    partOne();
    partTwo();
}
#include <iostream>
#include <fstream>
#include <filesystem>
#include <iterator>

int partOne() {
    std::ifstream input("..\\day01\\input.txt");

    int floor = 0;

    for (auto it = std::istream_iterator<char>(input);
         it != std::istream_iterator<char>();
         ++it) {
        switch(*it) {
            case '(': floor++; break;
            case ')': floor--; break;
            default: std::cerr << "Invalid input detected!" << std::endl; exit(1);
        }

    }

    std::cout << "\n" << "Part One: Floor " << floor << std::endl;
    return 0;
}

int partTwo() {
    std::ifstream input("..\\day01\\input.txt");

    int floor = 0;
    int pos = 0;
    bool reporting = true;

    for (auto it = std::istream_iterator<char>(input);
         it != std::istream_iterator<char>();
         ++it) {
        ++pos;
        switch(*it) {
            case '(': floor++; break;
            case ')': floor--; break;
            default: std::cerr << "Invalid input detected!" << std::endl; exit(1);
        }
        if (reporting && (floor == -1)) {
            std::cout << "Part Two: Position " << pos << std::endl;
            return 0;
        }

    }

    return 0;
}

int main() {
    partOne();
    partTwo();

    return 0;
}

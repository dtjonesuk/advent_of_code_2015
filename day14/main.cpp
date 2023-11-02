//
// Created by David on 02/11/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <cassert>
#include <numeric>
#include "Reindeer.h"


void test() {
    std::ifstream input("..\\day14\\test.txt");
    std::string line;

    std::vector<Reindeer> reindeer;

    while (std::getline(input, line)) {
        Reindeer r(line);
        reindeer.push_back(r);
    }

    for (int t = 0; t < 1000; t++) {
        for (Reindeer &r: reindeer) {
            r.Tick();
        }
    }

    Reindeer &r = *std::max_element(reindeer.begin(), reindeer.end(),
                                    [](auto &a, auto &b) { return a.getDistance() < b.getDistance(); });

    for (Reindeer &r : reindeer) {
        std::cout << r.name << " " << r.getDistance() << std::endl;
    }
    std::cout << "Test: " << r.name << r.getDistance() << std::endl;

}

void partOne() {
    std::ifstream input("..\\day14\\input.txt");
    std::string line;

    std::vector<Reindeer> reindeer;

    while (std::getline(input, line)) {
        Reindeer r(line);
        reindeer.push_back(r);
    }

    for (int t = 0; t < 2503; t++) {
        for (Reindeer &r: reindeer) {
            r.Tick();
        }
    }

    Reindeer &r = *std::max_element(reindeer.begin(), reindeer.end(),
                                    [](auto &a, auto &b) { return a.getDistance() < b.getDistance(); });

    std::cout << "Part one: " << r.name << " " << r.getDistance() << std::endl;
}

void partTwo() {
    std::ifstream input("..\\day14\\input.txt");
    std::string line;

    std::vector<Reindeer> reindeer;

    while (std::getline(input, line)) {
        Reindeer r(line);
        reindeer.push_back(r);
    }

    for (int t = 0; t < 2503; t++) {
        for (Reindeer &r: reindeer) {
            r.Tick();
        }
        // find reindeer in the lead
        Reindeer &leader = *std::max_element(reindeer.begin(), reindeer.end(),
                                        [](auto &a, auto &b) { return a.getDistance() < b.getDistance(); });
        int lead = leader.getDistance();

        // give all leading reindeer(s) a point
        for (Reindeer &r : reindeer) {
            if (r.getDistance() == lead)
                ++r.points;
        }

    }

    // get reindeer with most points
    Reindeer &r = *std::max_element(reindeer.begin(), reindeer.end(),
                                    [](auto &a, auto &b) { return a.points < b.points; });

    std::cout << "Part two: " << r.name << " " << r.points << std::endl;
}

int main() {
    test();
    partOne();
    partTwo();
}
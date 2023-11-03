#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cassert>

#include "Aunt.h"

std::map<std::string, int> parse_facts(std::ifstream &f) {
    std::regex re("(\\w+): (\\d+)");
    std::smatch smatch;
    std::string line;
    std::map<std::string, int> facts;

    while (std::getline(f, line)) {
        if (std::regex_search(line, smatch, re)) {
            std::string property = smatch.str(1);
            int value = std::stoi(smatch.str(2));
            facts[property] = value;
        }
    }

    return facts;
}


std::vector<Aunt> parse_aunts(std::ifstream &f) {
    std::vector<Aunt> aunts;
    std::string line;

    while (std::getline(f, line)) {
        aunts.emplace_back(line);
    }
    return aunts;
}

void partOne() {
    std::ifstream input("..\\day16\\input.txt");
    std::ifstream ifacts("..\\day16\\facts.txt");

    std::vector<Aunt> aunts = parse_aunts(input);
    std::map<std::string, int> facts = parse_facts(ifacts);

    auto last = aunts.end();

    // remove any aunt with a known fact that is wrong
    for (auto &[property, value]: facts) {
        // std::cout << property << ": " << value << std::endl;
        last = std::remove_if(aunts.begin(), last, [&](Aunt &aunt) {
            return aunt.properties.contains(property) && (aunt.properties.at(property) != value);
        });
    }
    // erase the "removed" aunts
    aunts.erase(last, aunts.end());

    std::cout << "Part One: " << aunts.size() << " / " << aunts.front().id << std::endl;
}

void partTwo() {
    std::ifstream input("..\\day16\\input.txt");
    std::ifstream ifacts("..\\day16\\facts.txt");

    std::vector<Aunt> aunts = parse_aunts(input);
    std::map<std::string, int> facts = parse_facts(ifacts);

    auto last = aunts.end();

    // remove any aunt with a known fact that is wrong
    for (auto &[property, value]: facts) {
        // std::cout << property << ": " << value << std::endl;
        last = std::remove_if(aunts.begin(), last, [&](Aunt &aunt) {
            if (aunt.properties.contains(property)) {
                if ((property == "cats") || (property == "trees")) {
                    // greater than this many = elminate fewer or equal
                    return aunt.properties.at(property) <= value;
                } else if ((property == "pomeranians") || (property == "goldfish")) {
                    // less than this many = eliminate more or equal
                    return aunt.properties.at(property) >= value;
                }
                // equal to this many = eliminate not equal
                return aunt.properties.at(property) != value;
            }
            return false;
        });
    }
    // erase the "removed" aunts
    aunts.erase(last, aunts.end());

    std::cout << "Part Two: " << aunts.size() << " / " << aunts.front().id << std::endl;
}

int main() {
    //test();
    partOne();
    partTwo();
}
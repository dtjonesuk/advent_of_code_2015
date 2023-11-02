//
// Created by David on 26/10/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <map>
#include <cassert>
#include <numeric>

#include "Person.h"
#include "Party.h"

void partOne() {
    std::ifstream input("..\\day13\\input.txt");
    std::string line;

    Party party;

    while (std::getline(input, line)) {
        party.parseAttendee(line);
    }

    auto& attendees = party.getAttendees();
    std::vector<Person> people;
    std::transform(attendees.cbegin(), attendees.cend(), std::back_inserter(people), [](auto p) { return p.second; });

    Permutation best;
    int bestHappiness = 0;

    do {
        Permutation p(people);
        int h = p.happiness();
        if (h > bestHappiness) {
            bestHappiness = h;
            best = p;

            std::cout << best << std::endl;
        }
    } while(std::next_permutation(people.begin(), people.end(), [](auto& a, auto& b) { return a.name < b.name; }));


    std::cout << "Part One: " << bestHappiness << std::endl;
}

void partTwo() {
    std::ifstream input("..\\day13\\input.txt");
    std::string line;

    Party party;

    while (std::getline(input, line)) {
        party.parseAttendee(line);
    }

    // add self to list
    party.addAttendee("Myself");

    auto& attendees = party.getAttendees();
    std::vector<Person> people;
    std::transform(attendees.cbegin(), attendees.cend(), std::back_inserter(people), [](auto p) { return p.second; });

    Permutation best;
    int bestHappiness = 0;

    do {
        Permutation p(people);
        int h = p.happiness();
        if (h > bestHappiness) {
            bestHappiness = h;
            best = p;

            std::cout << best << std::endl;
        }
    } while(std::next_permutation(people.begin(), people.end(), [](auto& a, auto& b) { return a.name < b.name; }));


    std::cout << "Part Two: " << bestHappiness << std::endl;
}

int main() {
    partOne();
    partTwo();
}
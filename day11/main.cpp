//
// Created by David on 26/10/2023.
//
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <cassert>
#include <regex>
#include <set>
#include <sstream>

#include "Password.h"

const std::string input = "cqjxjnds";
const std::string input2 = "cqjxxyzz";

void partOne() {
    Password p{input};
    p.increment();
    std::cout << "Part One: " << p.getPassword() << std::endl;
}

void partTwo() {
    Password p{input2};
    p.increment();
    std::cout << "Part Two: " << p.getPassword() << std::endl;
}

std::tuple<bool, bool, bool> testPassword(Password p) {
    bool a = p.checkStraight();
    bool b = p.checkBadLetters();
    bool c = p.checkPairs();
    std::cout << p.getPassword() << " : " << std::boolalpha << a << " " << b << " " << c << std::endl;
    return {a, b, c};

}

void doTests() {
    assert(testPassword({"hijklmmn"}) == std::make_tuple(true, false, false));
    assert(testPassword({"abbceffg"}) == std::make_tuple(false, true, true));
    assert(testPassword({"abbcegjk"}) == std::make_tuple(false, true, false));
    // testPassword({"ghjaabcc"});
    auto p = Password("abcdefgh");
    p.increment();
    assert(p.getPassword() == "abcdffaa");
    p = Password("ghijklmn");
    p.increment();
    assert(p.getPassword() == "ghjaabcc");

}

int main() {
    //doTests();

    partOne();
    partTwo();
}
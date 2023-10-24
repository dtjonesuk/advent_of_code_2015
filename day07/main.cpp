//
// Created by David on 22/10/2023.
//
#include <cassert>
#include "Parser.h"

void testParser() {
    Parser parser("..\\day07\\test.txt");
    parser.parse();

    std::map<std::string, int> results = {
            {"d", 72},
            {"e", 507},
            {"g", 114},
            {"h", 65412},
            {"i", 65079},
            {"x", 123},
            {"y", 456},
            {"f", 492},
    };
    for (auto &wire: parser.wires) {
        // std::cout << wire.first << ": " << wire.second.eval() << std::endl;
        assert(wire.second.getValue() == results[wire.first]);
    }
}

void partOne() {
    Parser parser("..\\day07\\input.txt");
    parser.parse();

//    for (auto &wire : parser.wires) {
//        std::cout << wire.first << ": " << wire.second.eval() << std::endl;
//    }

    unsigned short a = parser.wires.find("a")->second.getValue();

    std::cout << "a: " << a << std::endl;
}

void partTwo() {
    Parser parser("..\\day07\\input2.txt");
    parser.parse();

//    for (auto &wire : parser.wires) {
//        std::cout << wire.first << ": " << wire.second.eval() << std::endl;
//    }

    unsigned short a = parser.wires.find("a")->second.getValue();

    std::cout << "a: " << a << std::endl;
}


int main() {
    testParser();

    partOne();
    partTwo();
}
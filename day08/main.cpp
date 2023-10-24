//
// Created by David on 24/10/2023.
//
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <cassert>

// count the unused chars in a quote-string
int countChars(const std::string &str) {
    int len = str.size();
    int unused = 0;

    for (auto it = str.begin(); it != str.end(); ++it) {
        if (*it == '"') {
            ++unused;
        } else if (*it == '\\') {
            ++it;
            switch (*it) {
                case '\\':
                case '"':
                    ++unused;
                    break;
                case 'x':
                    std::string hex = {*++it, *++it};
                    unused += 3;
                    break;
            }
        }
    }

    return unused;
}

std::string encodeString(const std::string &str) {
    std::string output = "\"";
    for (auto it = str.begin(); it != str.end(); ++it) {
        if (*it == '"') {
            output += "\\\"";
        } else {
            if (*it == '\\') {
                ++it;
                switch (*it) {
                    case '\\':
                        output += "\\\\\\\\";
                        break;
                    case '\"':
                        output += "\\\\\\\"";
                        break;
                    case 'x':
                        std::string hex = {*++it, *++it};
                        output += "\\\\x" + hex;
                        break;
                }

            } else {
                output += *it;
            }
        }
    }
    output += "\"";
    return output;
}

void test(const std::string &str) {
    std::cout << str << " : " << encodeString(str) << " " << encodeString(str).size() << " " << str.size() << std::endl;
}

void testFunc() {
    assert(countChars("\"\"") == 2);
    assert(countChars("\"abc\"") == 2);
    assert(countChars("\"aaa\\\"aaa\"") == 3);
    assert(countChars("\"\\x27\"") == 5);

//    test("\"\"");
//    test("\"abc\"");
//    test("\"aaa\\\"aaa\"");
//    test("\"\\x27\"");


}

void partOne() {
    std::ifstream input("..\\day08\\input.txt");


    std::string line;
    int total = 0;

    while (std::getline(input, line)) {
        total += countChars(line);
    }

    std::cout << "Part One : " << total << std::endl;
}

void partTwo() {
    std::ifstream input("..\\day08\\input.txt");


    std::string line;
    int total = 0;

    while (std::getline(input, line)) {
        std::string encoded = encodeString(line);
        total += encoded.size() - line.size();
    }

    std::cout << "Part Two : " << total << std::endl;
}

int main() {
    testFunc();

    partOne();
    partTwo();
}
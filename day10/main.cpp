#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <cassert>
#include <regex>
#include <set>
#include <sstream>

const std::string input = "1113222113";

std::string lookAndSay(const std::string &str) {
    std::stringstream output;
    auto it = str.begin();

    while (it != str.end()) {
        char current = *it;
        int n = 0;
        while (it != str.end() && *it == current)
            ++it, ++n;

        output << n;
        output << current;
    }
    return output.str();
}

std::string testLookAndSay(const std::string &str) {
    std::string result = lookAndSay(str);
    std::cout << str << " " << result << std::endl;
    return result;
}

void test() {
    std::string s = testLookAndSay("1");
    s = testLookAndSay(s);
    s = testLookAndSay(s);
    s = testLookAndSay(s);
    s = testLookAndSay(s);
    s = testLookAndSay(s);
}

void partOne() {
    std::string str = input;
    for (int n = 0; n < 40; n++) {
        str = lookAndSay(str);
        // std::cout << str.size() << ", ";
    }

    std::cout << "Part One: " << str.size() << std::endl;
}

void partTwo() {
    std::string str = input;
    for (int n = 0; n < 50; n++) {
        str = lookAndSay(str);
        // std::cout << str.size() << ", ";
    }

    std::cout << "Part Two: " << str.size() << std::endl;
}

int main() {

    partOne();
    partTwo();
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <vector>

/* Part One functions */

bool isVowel(char ch) {
    return (ch == 'a') ||
            (ch == 'e') ||
            (ch == 'i') ||
            (ch == 'o') ||
            (ch == 'u');
}

bool hasDouble(const std::string& str) {
    for (auto it = str.begin(); it != str.end() - 1; it++) {
        char cur = *it;
        char nxt = *(it+1);
        if (cur == nxt)
            return true;
    }
    return false;
}

bool containsBadPair(const std::string& str) {
    const std::vector<std::string> badStrings = {"ab", "cd", "pq", "xy"};
    for (auto bad : badStrings) {
        if (str.find(bad) != std::string::npos)
            return true;
    }
    return false;
}

/* Part Two functions */

bool hasDoubleWithGap(const std::string& str) {
    for (auto it = str.begin(); it != str.end() - 2; it++) {
        char cur = *it;
        char nxt = *(it+2);
        if (cur == nxt)
            return true;
    }
    return false;
}

bool containsPair(const std::string& str) {
    for (auto it = str.begin(); it != str.end() - 1; it++) {
        char cur = *it;
        char nxt = *(it+1);

        // create two character string
        std::string pair{cur, nxt};

        // find the remainder of the input string
        auto target = std::string(it+2, str.end());

        // if remainder of string contains pair we have a pair
        if (target.find(pair) != std::string::npos) {
            // std::cout << "Pair " << pair << " found." << std::endl;
            return true;
        }
    }

    return false;
}

/*
 * A nice string is one with all of the following properties:
 * - It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
 * - It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
 * - It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.
 */

bool isNice(const std::string& str) {
    // count the vowels
    int vowels = std::count_if(str.begin(), str.end(), isVowel);
    // std::cout << "Vowels: " << vowels << std::endl;

    // check for doubles
    bool hasDoubleChar = hasDouble(str);
    // std::cout << "Doubles: " << hasDoubleChar << std::endl;

    // check for bad strings
    bool containsBadString = containsBadPair(str);
    // std::cout << "Contains bad: " << containsBadString << std::endl;

    return (vowels >= 3) && hasDoubleChar && !containsBadString;
}

/*
 * Now, a nice string is one with all of the following properties:
 * - It contains a pair of any two letters that appears at least twice in the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).
 * - It contains at least one letter which repeats with exactly one letter between them, like xyx, abcdefeghi (efe), or even aaa.
 */

bool isNice2(const std::string& str) {
    bool hasDouble = hasDoubleWithGap(str);

    bool hasPair = containsPair(str);

    return (hasDouble && hasPair);
}

void testIsNice() {
    assert(isNice("ugknbfddgicrmopn"));
    assert(isNice("aaa"));

    assert(!isNice("jchzalrnumimnmhp"));
    assert(!isNice("haegwjzuvuyypxyu"));
    assert(!isNice("dvszwmarrgswjxmb"));
}

void testIsNice2() {
    assert(isNice2("qjhvhtzxzqqjkmpb"));
    assert(isNice2("xxyxx"));

    assert(!isNice2("uurcxstgmygtbstg"));
    assert(!isNice2("ieodomkazucvgmuy"));
}
void partOne() {
    std::ifstream input("..\\day05\\input.txt");
    std::string line;
    int total = 0;

    while (std::getline(input, line)) {
        if (isNice(line))
            ++total;
    }

    std::cout << "Part One: total required = " << total << std::endl;

}

void partTwo() {
    std::ifstream input("..\\day05\\input.txt");
    std::string line;
    int total = 0;

    while (std::getline(input, line)) {
        if (isNice2(line))
            ++total;
    }

    std::cout << "Part Two: total required = " << total << std::endl;
}


int main() {
    testIsNice();
    testIsNice2();


    partOne();
    partTwo();
}
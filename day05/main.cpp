#include "../advent.h"

namespace day05 {
/// Change this to the current day
    static const std::string day = "05";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
    static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        std::vector<std::string> lines;

        explicit PuzzleInput(const std::string &filename) {
            std::ifstream istream(filename);
            std::string line;

            while (std::getline(istream, line)) {
                // do something
                lines.emplace_back(std::move(line));
            }
        }

    };

    bool isVowel(char ch) {
        return (ch == 'a') ||
               (ch == 'e') ||
               (ch == 'i') ||
               (ch == 'o') ||
               (ch == 'u');
    }

    bool hasDouble(const std::string &str) {
        for (auto it = str.begin(); it != str.end() - 1; it++) {
            char cur = *it;
            char nxt = *(it + 1);
            if (cur == nxt)
                return true;
        }
        return false;
    }

    bool containsBadPair(const std::string &str) {
        const std::vector<std::string> badStrings = {"ab", "cd", "pq", "xy"};
        for (auto bad: badStrings) {
            if (str.find(bad) != std::string::npos)
                return true;
        }
        return false;
    }

    bool hasDoubleWithGap(const std::string &str) {
        for (auto it = str.begin(); it != str.end() - 2; it++) {
            char cur = *it;
            char nxt = *(it + 2);
            if (cur == nxt)
                return true;
        }
        return false;
    }

    bool containsPair(const std::string &str) {
        for (auto it = str.begin(); it != str.end() - 1; it++) {
            char cur = *it;
            char nxt = *(it + 1);

            // create two character string
            std::string pair{cur, nxt};

            // find the remainder of the input string
            auto target = std::string(it + 2, str.end());

            // if remainder of string contains pair we have a pair
            if (target.find(pair) != std::string::npos) {
                // std::cout << "Pair " << pair << " found." << std::endl;
                return true;
            }
        }

        return false;
    }

    /*
     * A nice string is one with all the following properties:
     * - It contains at least three vowels (aeiou only), like aei, xazegov, or aeiouaeiouaeiou.
     * - It contains at least one letter that appears twice in a row, like xx, abcdde (dd), or aabbccdd (aa, bb, cc, or dd).
     * - It does not contain the strings ab, cd, pq, or xy, even if they are part of one of the other requirements.
     */

    bool isNice(const std::string &str) {
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
     * Now, a nice string is one with all the following properties:
     * - It contains a pair of any two letters that appears at least twice in the string without overlapping, like xyxy (xy) or aabcdefgaa (aa), but not like aaa (aa, but it overlaps).
     * - It contains at least one letter which repeats with exactly one letter between them, like xyx, abcdefeghi (efe), or even aaa.
     */

    bool isNice2(const std::string &str) {
        bool hasDouble = hasDoubleWithGap(str);

        bool hasPair = containsPair(str);

        return (hasDouble && hasPair);
    }


/// Unit Test
    void test() {
//    PuzzleInput input(testFilename);
        assert(isNice("ugknbfddgicrmopn"));
        assert(isNice("aaa"));

        assert(!isNice("jchzalrnumimnmhp"));
        assert(!isNice("haegwjzuvuyypxyu"));
        assert(!isNice("dvszwmarrgswjxmb"));

        assert(isNice2("qjhvhtzxzqqjkmpb"));
        assert(isNice2("xxyxx"));

        assert(!isNice2("uurcxstgmygtbstg"));
        assert(!isNice2("ieodomkazucvgmuy"));
    }

/// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        int total = std::count_if(input.lines.begin(), input.lines.end(), [](const std::string &line) {
            return isNice(line);
        });

        return total;
    }


/// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);

        int total = std::count_if(input.lines.begin(), input.lines.end(), [](const std::string &line) {
            return isNice2(line);
        });

        return total;
    }
}

int main() {
    using namespace day05;
    test();

    {
        std::cout << std::fixed << std::setprecision(3);
        auto [seconds, result] = advent::eval<int>(&partOne);

        std::cout << "Day " << day << ": Part One = " << result << "\t\t (completed in " << seconds << "s).\n";
    }
    {
        std::cout << std::fixed << std::setprecision(3);
        auto [seconds, result] = advent::eval<int>(&partTwo);

        std::cout << "Day " << day << ": Part One = " << result << "\t\t (completed in " << seconds << "s).\n";
    }
}




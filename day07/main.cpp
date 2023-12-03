#include "../advent.h"
#include "Parser.h"

namespace day07 {
/// Change this to the current day
    static const std::string day = "07";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
    static const std::string input2Filename = "..\\day" + day + "\\input2.txt";
    static const std::string testFilename = "..\\day" + day + "\\test.txt";

//    struct PuzzleInput {
//        std::vector<std::string> lines;
//
//        explicit PuzzleInput(const std::string &filename) {
//            std::ifstream istream(filename);
//            std::string line;
//
//            while (std::getline(istream, line)) {
//                // do something
//                lines.emplace_back(std::move(line));
//            }
//        }
//
//    };

/// Unit Test
    void test() {
        Parser parser(testFilename);
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
            assert(wire.second.getValue() == results[wire.first]);
        }
    }

/// Part One Solution
    int partOne() {
        Parser parser(inputFilename);
        parser.parse();

        unsigned short a = parser.wires.find("a")->second.getValue();
        return a;
    }


/// Part Two Solution
    int partTwo() {
        Parser parser(input2Filename);
        parser.parse();

        unsigned short a = parser.wires.find("a")->second.getValue();
        return a;
    }
}

int main() {
    using namespace day07;
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

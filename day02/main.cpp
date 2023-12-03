#include "../advent.h"
#include "Present.h"

namespace day02 {
    /// Change this to the current day
    static const std::string day = "02";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
    static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        std::vector<Present> presents;

        explicit PuzzleInput(const std::string &filename) {
            std::ifstream istream(filename);
            std::string line;

            while (std::getline(istream, line)) {
                // do something
                std::stringstream ss(line);
                int length, width, height;
                char x;

                if (ss >> length >> x >> width >> x >> height) {
                    presents.emplace_back(length, width, height);
                }
            }
        }
    };


    /// Unit Test
    void test() {
//        PuzzleInput input(testFilename);
        assert(Present(2, 3, 4).ribbonRequired() == 34);
        assert(Present(1, 1, 10).ribbonRequired() == 14);
        assert(Present(2, 3, 4).paperRequired() == 58);
        assert(Present(1, 1, 10).paperRequired() == 43);
    }

    /// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        int totalRequired = std::reduce(input.presents.begin(), input.presents.end(), 0,
                                        [](int total, Present &present) {
                                            return total + present.paperRequired();
                                        });

        return totalRequired;
    }


    /// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);
        int totalRequired = std::reduce(input.presents.begin(), input.presents.end(), 0,
                                        [](int total, Present &present) {
                                            return total + present.ribbonRequired();
                                        });

        return totalRequired;
    }
}

int main() {
    using namespace day02;
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



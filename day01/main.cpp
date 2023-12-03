#include "../advent.h"

namespace day01 {
    /// Change this to the current day
    static const std::string day = "01";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
    static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        std::string text;

        explicit PuzzleInput(const std::string &filename) {
            std::ifstream istream(filename);
            std::string line;

            while (std::getline(istream, line)) {
                // do something
                text = std::move(line);
            }
        }

    };

    /// calculates the end floor a given set of input instructions arrives at
    int calc_floor(const std::string &input) {
        int floor = std::reduce(input.begin(), input.end(), 0, [](int floor, char c) {
            switch (c) {
                case '(':
                    return ++floor;
                    break;
                case ')':
                    return --floor;
                    break;
                default:
                    throw std::runtime_error("Invalid input detected!");
            }
        });

        return floor;
    }

    /// Unit Test
    void test() {
//        PuzzleInput input(testFilename);#
        assert(calc_floor("(())") == 0);
        assert(calc_floor("()()") == 0);
        assert(calc_floor("(((") == 3);
        assert(calc_floor("(()(()(") == 3);
        assert(calc_floor("))(((((") == 3);
        assert(calc_floor("())") == -1);
        assert(calc_floor("))(") == -1);
        assert(calc_floor(")))") == -3);
        assert(calc_floor(")())())") == -3);
    }

    /// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        return calc_floor(input.text);
    }


    /// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);

        int floor = 0;
        int pos = 0;

        for (char c: input.text) {
            ++pos;
            switch (c) {
                case '(':
                    floor++;
                    break;
                case ')':
                    floor--;
                    break;
                default:
                    std::cerr << "Invalid input detected!" << std::endl;
                    exit(1);
            }
            // early exit when we reach the basement!
            if (floor == -1) {
                return pos;
            }

        }
        // should never reach here
        return -1;
    }
}

int main() {
    using namespace day01;
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



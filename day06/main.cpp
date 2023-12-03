#include "../advent.h"
#include "Command.h"

namespace day06 {
/// Change this to the current day
    static const std::string day = "06";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
    static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        std::vector<Command> commands;

        explicit PuzzleInput(const std::string &filename) {
            std::ifstream istream(filename);
            std::string line;

            while (std::getline(istream, line)) {
                commands.emplace_back(line);
            }
        }

    };

    constexpr int size_x = 1000;
    constexpr int size_y = 1000;

    constexpr int index(int x, int y) { return y * size_y + x; }

/// Unit Test
    void test() {
        PuzzleInput input(testFilename);
        assert(true);
    }

/// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        std::vector<int> lights(size_x * size_y, 0);

        // operate on the block of lights
        for (Command &command : input.commands) {
            for (int x = command.from.first; x <= command.to.first; x++) {
                for (int y = command.from.second; y <= command.to.second; y++) {
                    switch (command.cmd) {
                        case turn_on:
                            lights[index(x, y)] = 1;
                            break;
                        case turn_off:
                            lights[index(x, y)] = 0;
                            break;
                        case toggle:
                            lights[index(x, y)] = !lights[index(x, y)];
                            break;
                    }
                }
            }
        }

        // calculate how many lights are on
        int total = std::count(lights.begin(), lights.end(), 1);

        return total;
    }


/// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);

        std::vector<int> lights(size_x * size_y, 0);

        // operate on the block of lights
        for (Command &command : input.commands) {
            for (int x = command.from.first; x <= command.to.first; x++) {
                for (int y = command.from.second; y <= command.to.second; y++) {
                    switch (command.cmd) {
                        case turn_on:
                            lights[index(x, y)] += 1;
                            break;
                        case turn_off:
                            lights[index(x, y)] = std::max(lights[index(x, y)] - 1, 0);
                            break;
                        case toggle:
                            lights[index(x, y)] += 2;
                            break;
                    }
                }
            }
        }

        // calculate how many lights are on
        int total = std::accumulate(lights.begin(), lights.end(), 0);

        return total;
    }
}

int main() {
    using namespace day06;
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
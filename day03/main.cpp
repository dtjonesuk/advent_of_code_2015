#include "../advent.h"

#include "Santa.h"

namespace day03 {
/// Change this to the current day
    static const std::string day = "03";
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

/// Unit Test
    void test() {
        PuzzleInput input(testFilename);
        assert(true);
    }

/// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);

        LocationMap locations;
        Santa santa(locations);

        // Santa puts a present at start location
        locations[santa.currentLocation] = 1;

        for (char c : input.text) {
            // Move santa and place present
            santa.move(c);
        }

        return locations.size();
    }


/// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);

        LocationMap locations;
        Santa santa(locations), robo_santa(locations);

        // Santa puts a present at start location
        // Robo Santa starts at same location so just one present
        locations[santa.currentLocation] = 1;


        for (auto it = input.text.begin(); it != input.text.end(); ++it) {
            // Move santa
            santa.move(*it);

            // Next instruction
            ++it;

            // Move Robo Santa
            robo_santa.move(*it);
        }

        return locations.size();
    }
}

int main() {
    using namespace day03;
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
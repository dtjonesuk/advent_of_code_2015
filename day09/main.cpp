#include "../advent.h"
#include "Cities.h"
#include "Trip.h"

namespace day09 {
/// Change this to the current day
    static const std::string day = "09";
    static const std::string inputFilename = "..\\day" + day + "\\input.txt";
//static const std::string testFilename = "..\\day" + day + "\\test.txt";

    struct PuzzleInput {
        Cities cities;

        explicit PuzzleInput(const std::string &filename) {
            std::ifstream istream(filename);
            std::string line;

            while (std::getline(istream, line)) {
                // do something
                cities.insert(line);
            }
        }
    };


/// Unit Test
    void test() {
        assert(true);
    }

/// Part One Solution
    int partOne() {
        PuzzleInput input(inputFilename);
        Cities& cities = input.cities;

        // Find all trips
        std::cout << "Searching for trips..." << std::flush << "\r";
        TripList trips = cities.find_trips();

        // Find the shortest trip
        auto &shortest = *std::min_element(trips.begin(), trips.end(), [](Trip a, Trip b) {
            return a.distance() < b.distance();
        });

        return shortest.distance();
    }


/// Part Two Solution
    int partTwo() {
        PuzzleInput input(inputFilename);
        Cities& cities = input.cities;

        // Find all trips
        std::cout << "Searching for trips..." << std::flush << "\r";
        TripList trips = cities.find_trips();

        // Find the longest trip
        auto &longest = *std::max_element(trips.begin(), trips.end(), [](Trip a, Trip b) {
            return a.distance() < b.distance();
        });

        return longest.distance();
    }

}

int main() {
    using namespace day09;
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

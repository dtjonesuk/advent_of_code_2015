#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <cassert>

using location_t = std::pair<int, int>;
using locationmap_t = std::map<location_t, int>;

struct Santa {
    location_t currentLocation{0, 0};
    locationmap_t& locations;

    explicit Santa(locationmap_t& l) : locations(l) {}

    void move(char ch) {
        // move current location 1 square (based on ch), then add a present at new location
        switch (ch) {
            case '^':
                currentLocation.second += 1;
                locations[currentLocation] += 1;
                break;
            case '>':
                currentLocation.first += 1;
                locations[currentLocation] += 1;
                break;
            case 'v':
                currentLocation.second -= 1;
                locations[currentLocation] += 1;
                break;
            case '<':
                currentLocation.first -= 1;
                locations[currentLocation] += 1;
                break;
            default:
                std::cerr << "Invalid input detected!" << std::endl;
                exit(1);
        }

    }

};

void partOne() {
    std::ifstream input("..\\day03\\input.txt");
    std::string line;
    locationmap_t locations;

    Santa santa(locations);

    // santa puts a present at start location
    locations[santa.currentLocation] = 1;

    for (auto it = std::istream_iterator<char>(input);
         it != std::istream_iterator<char>();
         ++it) {
        // move santa and place present
        santa.move(*it);
    }

    std::cout << "Part One: total visited locations = " << locations.size() << std::endl;

}

void partTwo() {
    std::ifstream input("..\\day03\\input.txt");
    std::string line;
    locationmap_t locations;

    Santa santa(locations), roboSanta(locations);
    // santa puts a present at start location - (robo santa starts at same location so just one present?)
    locations[santa.currentLocation] = 1;


    for (auto it = std::istream_iterator<char>(input);
         it != std::istream_iterator<char>();
         ++it) {

        santa.move(*it);

        ++it;
        roboSanta.move(*it);

    }

    std::cout << "Part Two: total visited locations = " << locations.size() << std::endl;

}


int main() {
    partOne();
    partTwo();
}
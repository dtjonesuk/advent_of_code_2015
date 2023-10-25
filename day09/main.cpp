//
// Created by David on 24/10/2023.
//
#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <cassert>
#include <regex>
#include <set>

#include "Cities.h"


void printTrip(Trip trip) {
    int total = 0;
    for (auto &r: trip) {
        std::cout << r.city().name << " (" << r.distance << "), ";
        total += r.distance;
    }
    std::cout << "Total = " << total << std::endl;
}

TripList visitCity(City &city, VisitedSet &visited, const Trip &trip) {
    visited.insert(city.name);
    TripList trips;
    for (auto route: city.routes) {
        Trip newTrip = trip;
        if (!visited.contains(route.destination)) {
            // add route to trip
            newTrip.push_back(route);
            // set visited flag
            std::set<std::string> newVisited = visited;

            // recursive
            TripList newTrips = visitCity(route.city(), newVisited, newTrip);
            trips.insert(trips.end(), newTrips.begin(), newTrips.end());

            // if we have visited all cities then this is a complete trip
            if (newVisited.size() == City::Cities.size()) {
                trips.push_back(newTrip);
                //printTrip(newTrip);
            }
        }
    }
    return trips;
}

TripList findTrips() {
    TripList trips;
    for (auto &[name, startCity]: City::Cities) {
        VisitedSet visited;
        Trip trip;

        trip.push_back({startCity.name, 0});

        TripList newTrips = visitCity(startCity, visited, trip);
        trips.insert(trips.end(), newTrips.begin(), newTrips.end());

        //printTrip(trip);
    }
    //std::cout << trips.size();
    return trips;
}

void printCities() {
    for (auto &[name, city]: City::Cities) {
        std::cout << name << ":" << std::endl;
        for (auto &route: city.routes) {
            std::cout << "    " << route.city().name << " - " << route.distance << std::endl;
        }
    }
}

void insertCity(const std::string &line) {
    //std::string line = "London to Dublin = 464";
    std::regex ex("(.+) to (.+) = (\\d+)");

    std::smatch m;

    if (std::regex_search(line, m, ex)) {
        //std::cout << "Regex match!" << std::endl;

        std::string from = m[1];
        std::string to = m[2];
        int distance = stoi(m[3]);

        if (!City::Cities.contains(from))
            City::Cities[from] = {from};

        if (!City::Cities.contains(to))
            City::Cities[to] = {to};


        City::Cities[from].routes.push_back({to, distance});
        City::Cities[to].routes.push_back({from, distance});

    }
}


void partOne() {
    std::ifstream input("..\\day09\\input.txt");
    std::string line;

    while (std::getline(input, line)) {
        insertCity(line);
    }

    // Initialize Cities
    int numCities = City::Cities.size();
    std::cout << "Read " << numCities << " cities." << std::endl;
    if (numCities == 0)
        return;

    // Find all trips
    TripList trips = findTrips();

    // Find shortest trip
    auto& shortest = *std::min_element(trips.begin(), trips.end(), [](Trip a, Trip b){
        return a.distance() < b.distance();
    });

    // Print result
    std::cout << "Part One: shortest trip is " << shortest.distance() << std::endl;
    printTrip(shortest);
}

void partTwo() {
    std::ifstream input("..\\day09\\input.txt");
    std::string line;

    while (std::getline(input, line)) {
        insertCity(line);
    }

    // Initialize Cities
    int numCities = City::Cities.size();
    std::cout << "Read " << numCities << " cities." << std::endl;
    if (numCities == 0)
        return;

    // Find all trips
    TripList trips = findTrips();

    // Find longest trip
    auto& longest = *std::max_element(trips.begin(), trips.end(), [](Trip a, Trip b){
        return a.distance() < b.distance();
    });

    // Print result
    std::cout << "Part Two: longest trip is " << longest.distance() << std::endl;
    printTrip(longest);
}

void testTrips() {
    insertCity("London to Dublin = 464");
    insertCity("London to Belfast = 518");
    insertCity("Dublin to Belfast = 141");

    printCities();
    findTrips();
}

int main() {
    partOne();
    partTwo();
}
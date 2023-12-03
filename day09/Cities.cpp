//
// Created by David on 03/12/2023.
//

#include "Cities.h"

namespace day09 {
    TripList Cities::find_trips() const {
        TripList trips;

        std::for_each(std::execution::seq, cities.begin(), cities.end(), [&](auto& pair) {
            auto& [name, start_city] = pair;

            VisitedSet visited;
            Trip trip;

            trip.routes.push_back({start_city.name, 0});

            TripList newTrips = visit_city(start_city, visited, trip);

            trips.insert(trips.end(), newTrips.begin(), newTrips.end());
        });

        return trips;
    }

    TripList Cities::visit_city(const City &city, VisitedSet &visited, const Trip &trip) const {
        visited.insert(city.name);
        TripList trips;

        for (auto route: city.routes) {
            Trip newTrip = trip;
            if (!visited.contains(route.destination)) {
                // add route to trip
                newTrip.routes.push_back(route);
                // set visited flag
                std::set<std::string> newVisited = visited;

                // recursive
                TripList newTrips = visit_city(cities.at(route.destination), newVisited, newTrip);
                trips.insert(trips.end(), newTrips.begin(), newTrips.end());

                // if we have visited all cities then this is a complete trip
                if (newVisited.size() == cities.size()) {
                    trips.push_back(newTrip);
                }
            }
        }

        return trips;
    }

    void Cities::insert(const std::string &line) {
        std::smatch m;

        if (std::regex_search(line, m, re)) {
            std::string from = m[1];
            std::string to = m[2];
            int distance = stoi(m[3]);

            if (!cities.contains(from))
                cities.emplace(from, from);

            if (!cities.contains(to))
                cities.emplace(to, to);

            cities.at(from).routes.emplace_back(to, distance);
            cities.at(to).routes.emplace_back(from, distance);
        }
    }

    int Cities::size() const {
        return cities.size();
    }

    void Cities::print(std::ostream &os) const {
        for (auto &[name, city]: cities) {
            os << name << ":" << std::endl;
            for (auto &route: city.routes) {
                os << "    " << cities.at(route.destination).name << " - " << route.distance << std::endl;
            }
        }
    }
} // day09
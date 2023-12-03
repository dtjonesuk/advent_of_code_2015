//
// Created by David on 03/12/2023.
//

#ifndef INC_2015_CITIES_H
#define INC_2015_CITIES_H

#include <string>
#include <map>
#include <regex>
#include <algorithm>
#include <execution>

#include "City.h"
#include "Trip.h"

namespace day09 {

    class Cities {
    public:
        int size() const;

        void insert(const std::string &line);

        TripList visit_city(const City &city, VisitedSet &visited, const Trip &trip) const;

        TripList find_trips() const;

        void print(std::ostream& os) const;

        std::map<std::string, City> cities;
    private:
        const std::regex re{"(.+) to (.+) = (\\d+)"};
    };

} // day09

#endif //INC_2015_CITIES_H

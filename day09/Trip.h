//
// Created by David on 03/12/2023.
//

#ifndef INC_2015_TRIP_H
#define INC_2015_TRIP_H

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <numeric>

#include "City.h"

namespace day09 {
    class Trip {
    public:
        int distance();

        void print(std::ostream &os);

        std::vector<Route> routes;
    };

    typedef std::vector<Trip> TripList;
    typedef std::set<std::string> VisitedSet;


}
#endif //INC_2015_TRIP_H

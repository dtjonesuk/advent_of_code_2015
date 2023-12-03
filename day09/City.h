//
// Created by David on 03/12/2023.
//

#ifndef INC_2015_CITY_H
#define INC_2015_CITY_H
#include <string>
#include <vector>
#include <map>


namespace day09 {
    struct Route {
        std::string destination;
        int distance;
    };

    struct City {
        City(const std::string& name);
        std::string name;
        std::vector<Route> routes;
    };
}
#endif //INC_2015_CITY_H

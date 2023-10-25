//
// Created by David on 25/10/2023.
//

#ifndef INC_2015_CITIES_H
#define INC_2015_CITIES_H
#include <string>
#include <map>
#include <numeric>

struct City;
struct Route;

struct City {
    std::string name;
    std::vector<Route> routes;

    static std::map<std::string, City> Cities;
};

struct Route {
    std::string destination;
    int distance;

    City& city() {
        return City::Cities[destination];
    }
};

class Trip : public std::vector<Route> {
public:
  int distance() {
      return std::accumulate(begin(), end(), 0, [](auto acc, auto& r){
          return std::move(acc) + r.distance;
      });
  }
};
//typedef std::vector<Route> Trip;
typedef std::vector<Trip> TripList;
typedef std::set<std::string> VisitedSet;

std::map<std::string, City> City::Cities;

#endif //INC_2015_CITIES_H

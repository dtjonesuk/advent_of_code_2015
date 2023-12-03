//
// Created by David on 03/12/2023.
//

#ifndef INC_2015_SANTA_H
#define INC_2015_SANTA_H
#include <map>
#include <stdexcept>

using Location = std::pair<int, int>;
using LocationMap = std::map<Location, int>;

struct Santa {
    Location currentLocation{0, 0};
    LocationMap& locations;

    explicit Santa(LocationMap& l);

    void move(char ch);

};


#endif //INC_2015_SANTA_H

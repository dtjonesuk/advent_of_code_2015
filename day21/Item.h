//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_ITEM_H
#define INC_2015_ITEM_H

#include <string>

class Item {
public:
    Item(const std::string &name, int cost, int damage, int armor)
            : cost(cost), damage(damage), armor(armor), name(name) {}

    virtual ~Item() = default;

    std::string name;
    int cost{0};
    int damage{0};
    int armor{0};
};


#endif //INC_2015_ITEM_H

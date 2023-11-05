//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_SHOP_H
#define INC_2015_SHOP_H

#include <string>
#include <vector>

#include "Item.h"

class Shop {
public:
    Shop();
    std::vector<Item> weapons;
    std::vector<Item> armor;
    std::vector<Item> rings;
};


#endif //INC_2015_SHOP_H

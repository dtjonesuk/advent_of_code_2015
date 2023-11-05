//
// Created by David on 05/11/2023.
//

#include "Shop.h"

Shop::Shop() {
    weapons.push_back({"Dagger", 8, 4, 0});
    weapons.push_back({"Shortsword", 10, 5, 0});
    weapons.push_back({"Warhammer", 25, 6, 0});
    weapons.push_back({"Longsword", 40, 7, 0});
    weapons.push_back({"Greataxe", 74, 8, 0});

    armor.push_back({"Leather", 13, 0, 1});
    armor.push_back({"Chainmail", 31, 0, 2});
    armor.push_back({"Splintmail", 53, 0, 3});
    armor.push_back({"Bandedmail", 75, 0, 4});
    armor.push_back({"Platemail", 102, 0, 5});

    rings.push_back({"Damage +1", 25, 1, 0});
    rings.push_back({"Damage +2", 50, 2, 0});
    rings.push_back({"Damage +3", 100, 3, 0});
    rings.push_back({"Defense +1", 20, 0, 1});
    rings.push_back({"Defense +2", 40, 0, 2});
    rings.push_back({"Defense +3", 80, 0, 3});
}

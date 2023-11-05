#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Character.h"
#include "Battle.h"
#include "Shop.h"

//bool battle(Player player) {
//    Boss boss(103, 9, 2);
//    Battle battle(player, boss);
//
//    return battle.simulate();
//}

void partOne() {
//    Player player(100, 5, 5);
    Shop shop;
    Player winner(0, 0, 0);
    Boss boss(103, 9, 2);
    Battle battle(boss);

    for (Item weapon: shop.weapons) {
        // must choose 1
        Player player({weapon});
        battle.battle(player);

        for (Item armor: shop.armor) {
            // optional
            Player player({weapon, armor});
            battle.battle(player);

            for (Item ring1: shop.rings) {
                // may choose 0-2
                {
                    Player player({weapon, ring1});
                    battle.battle(player);
                }
                {
                    Player player({weapon, armor, ring1});
                    battle.battle(player);
                }
                std::vector<Item> rings_left;
                std::remove_copy_if(shop.rings.begin(), shop.rings.end(), std::back_inserter(rings_left), [&](const Item& itm) {
                    return itm.name == ring1.name;
                });

                for (Item ring2: rings_left) {
                    {
                        Player player({weapon, armor, ring1, ring2});
                        battle.battle(player);
                    }
                    {
                        Player player({weapon, ring1, ring2});
                        battle.battle(player);
                    }
                }
            }
        }
    }

    for (Item item : battle.winner.items) {
        std::cout << item.name << " ";
    }

    std::cout << "\nDay 21: Part One=" << battle.winner.spent() << std::endl;
}

void partTwo() {
//    Player player(100, 5, 5);
    Shop shop;
    Player winner(0, 0, 0);
    Boss boss(103, 9, 2);
    LosingBattle battle(boss);

    for (Item weapon: shop.weapons) {
        // must choose 1
        Player player({weapon});
        battle.battle(player);

        for (Item armor: shop.armor) {
            // optional
            Player player({weapon, armor});
            battle.battle(player);

            for (Item ring1: shop.rings) {
                // may choose 0-2
                {
                    Player player({weapon, ring1});
                    battle.battle(player);
                }
                {
                    Player player({weapon, armor, ring1});
                    battle.battle(player);
                }
                std::vector<Item> rings_left;
                std::remove_copy_if(shop.rings.begin(), shop.rings.end(), std::back_inserter(rings_left), [&](const Item& itm) {
                    return itm.name == ring1.name;
                });

                for (Item ring2: rings_left) {
                    {
                        Player player({weapon, armor, ring1, ring2});
                        battle.battle(player);
                    }
                    {
                        Player player({weapon, ring1, ring2});
                        battle.battle(player);
                    }
                }
            }
        }
    }

    for (Item item : battle.winner.items) {
        std::cout << item.name << " ";
    }

    std::cout << "\nDay 21: Part Two=" << battle.winner.spent() << std::endl;
}

int main() {
    partOne();
    partTwo();
}
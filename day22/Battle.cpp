//
// Created by David on 05/11/2023.
//

#include "Battle.h"
#include <iostream>
#include <numeric>


bool Battle::battle(Player &player) {
    Boss boss{this->boss};
    if (simulate(player, boss)) {
        if (player.spent() < winner.spent())
            winner = player;
//        std::cout << "Player wins! " << player.spent() << std::endl;
        return true;
    }
    return false;
}

bool Battle::simulate(Player &player, Boss &boss) {
    while ((player.hp() > 0) && (boss.hp() > 0)) {

        // player turn
        int damage_done = boss.apply_damage(player.damage());
        // std::cout << "Player does " << damage_done << " damage; Boss hp is " << boss.hp() << std::endl;

        if (boss.hp() <= 0) {
            // player wins
            return true;
        }

        damage_done = player.apply_damage(boss.damage());
        // std::cout << "Boss does " << damage_done << " damage; Player hp is " << player.hp() << std::endl;
        if (player.hp() <= 0) {
            // player loses
            return false;
        }
    }
}

//bool LosingBattle::battle(Player &player) {
//    Boss boss{this->boss};
//    if (!simulate(player, boss)) {
//        if (player.spent() > winner.spent())
//            winner = player;
////        std::cout << "Player wins! " << player.spent() << std::endl;
//        return true;
//    }
//    return false;
//}

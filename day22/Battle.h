//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_BATTLE_H
#define INC_2015_BATTLE_H

#include "Character.h"
#include <numeric>
#include <functional>

class Battle {
public:
    Battle(Boss boss) : boss(boss) {}

    bool battle(Player &player);

    bool simulate(Player &player, Boss &boss);

    Player winner{0, 0, 0};

protected:
    Boss boss;
};


#endif //INC_2015_BATTLE_H

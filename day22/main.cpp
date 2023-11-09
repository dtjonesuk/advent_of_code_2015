#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Character.h"
#include "Battle.h"

void partOne() {
    Player winner(0, 0, 0);
    Boss boss(103, 9, 2);
    Battle battle(boss);

    std::cout << "\nDay 21: Part One=" << battle.winner.spent() << std::endl;
}

void partTwo() {
}

int main() {
    partOne();
    partTwo();
}
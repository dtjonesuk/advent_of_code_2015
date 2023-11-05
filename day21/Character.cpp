//
// Created by David on 05/11/2023.
//

#include <iostream>
#include "Character.h"

int Character::hp() {
    return hitpoints;
}

int Character::damage() {
    return dmg;
}

int Character::armor() {
    return arm;
}

// apply damage and return true if still alive
int Character::take_damage(int damage) {
    int actual_damage = std::max(1, damage - armor());
    hitpoints -= actual_damage;
    return actual_damage;
}

Player::Player(const std::vector<Item> &items) : Character(100), items(items) {
    name = "Player";
    for (auto& item : items) {
        dmg += item.damage;
        arm += item.armor;
        cost += item.cost;
    }
}

int Player::spent() {
    return cost;
}

Player::Player(int hp, int damage, int armor) : Character(hp) {
    name = "Player";
    dmg = damage;
    arm = armor;
    cost = INT32_MAX;
}

Boss::Boss(int hitpoints, int damage, int armor) : Character(hitpoints) {
    name = "Boss";
    dmg = damage;
    arm = armor;
}

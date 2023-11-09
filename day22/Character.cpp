//
// Created by David on 05/11/2023.
//

#include <iostream>
#include "Character.h"

int Character::hp() {
    return hitpoints;
}

int Character::damage() {
    return _damage;
}

int Character::armor() {
    return _armor;
}

// apply damage and return true if still alive
int Character::apply_damage(int damage) {
    int actual_damage = std::max(1, damage - armor());
    hitpoints -= actual_damage;
    return actual_damage;
}

int Character::apply_healing(int healing) {
    hitpoints += healing;
    return healing;
}

int Character::apply_armor(int armor, bool temporary) {
    _armor_boost += armor;
    return _armor_boost;
}

int Character::apply_mana(int mana) {
    _mana += mana;
    return mana;
}

void Character::apply_effects() {
    std::vector<Effect*> effects;
    for (Effect* effect : _active_effects) {
        if (effect->apply())
            effects.push_back(effect);
    }
    _active_effects = effects;
}

int Player::spent() {
    return cost;
}

Player::Player(int hp, int mana) : Character(hp) {
    name = "Player";
    _mana = mana;
    _damage = 0;
    _armor = 0;
    cost = INT32_MAX;
}

Boss::Boss(int hitpoints, int damage, int armor) : Character(hitpoints) {
    name = "Boss";
    _damage = damage;
    _armor = armor;
}

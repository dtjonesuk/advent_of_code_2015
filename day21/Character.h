//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_CHARACTER_H
#define INC_2015_CHARACTER_H
#include <string>
#include <vector>
#include "Item.h"

class Character {
public:
    Character(int max_hp) : max_hp(max_hp), hitpoints(max_hp) {}
    virtual ~Character() = default;

    virtual int take_damage(int damage);
    virtual int damage();
    virtual int armor();
    virtual int hp();

protected:
    std::string name;
    int hitpoints;
    int max_hp;
    int dmg{0};
    int arm{0};
};

class Player : public Character {
public:
    Player(const std::vector<Item> &items);
    Player(int hp, int damage, int armor);
    std::vector<Item> items;

    int spent();

public:
    int cost{0};

};

class Boss : public Character {
public:
    Boss(int hitpoints, int damage, int armor);


};
#endif //INC_2015_CHARACTER_H

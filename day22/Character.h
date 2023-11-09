//
// Created by David on 05/11/2023.
//

#ifndef INC_2015_CHARACTER_H
#define INC_2015_CHARACTER_H
#include <string>
#include <vector>
//#include "Effect.h"
class Effect;

class Character {
public:
    Character(int max_hp) : max_hp(max_hp), hitpoints(max_hp) {}
    virtual ~Character() = default;

    void apply_effects();
    virtual int apply_damage(int damage);
    virtual int apply_healing(int healing);
    virtual int apply_armor(int armor, bool temporary = true);
    virtual int apply_mana(int mana);
    virtual int damage();
    virtual int armor();
    virtual int hp();

protected:
    std::string name;
    int hitpoints;
    int max_hp;
    int _mana{0};
    int _damage{0};
    int _armor{0};
    int _armor_boost{0};
    std::vector<Effect*> _active_effects;
};

class Player : public Character {
public:
    Player(int hp, int mana);

    int spent();

public:
    int cost{0};

};

class Boss : public Character {
public:
    Boss(int hitpoints, int damage, int armor);
};
#endif //INC_2015_CHARACTER_H

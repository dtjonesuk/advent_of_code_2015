//
// Created by David on 06/11/2023.
//

#ifndef INC_2015_SPELL_H
#define INC_2015_SPELL_H

#include "Character.h"
#include "Effect.h"


class Spell {
public:
    Spell(Character &caster, std::string name, int cost);

    virtual ~Spell();

    virtual Effect *cast(Character &target) = 0;

protected:
    Character &_caster;
    std::string _name;
    int _cost{0};
};

class MagicMissileSpell : public Spell {
public:
    Effect *cast(Character &target) override;
};

class DrainSpell : public Spell {
public:
    Effect *cast(Character &target) override;
};

class ShieldSpell : public Spell {
public:
    Effect *cast(Character &target) override;
};

class PoisonSpell : public Spell {
public:
    Effect *cast(Character &target) override;
};

class RechargeSpell : public Spell {
public:
    Effect *cast(Character &target) override;
};


#endif //INC_2015_SPELL_H

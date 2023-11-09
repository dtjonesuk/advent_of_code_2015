#ifndef INC_2015_EFFECT_H
#define INC_2015_EFFECT_H

#include "Character.h"

class Effect {
public:
    Effect(Character &caster, Character &target, int turns = 0);

    virtual ~Effect();

    bool is_instant() const;

    bool apply();

    virtual void apply_turn(int turn);

protected:
    int _turns{0};
    int _turns_left{0};
    Character &_caster;
    Character &_target;
};

class InstantDamageEffect : public Effect {
public:
    InstantDamageEffect(Character &caster, Character &target, int damage) : Effect(caster, target), _damage(damage) {}

    void apply_turn(int turn) override;

private:
    int _damage{0};
};

class InstantDrainEffect : public Effect {
public:
    InstantDrainEffect(Character &caster, Character &target, int amount) : Effect(caster, target),
                                                                           _amount(amount) {}

    void apply_turn(int turn) override;

private:
    int _amount{0};

};

class ShieldEffect : public Effect {
public:
    ShieldEffect(Character &caster, Character &target, int turns, int armor) : Effect(caster, target, turns), _armor(armor) {}

    void apply_turn(int turn) override;
private:
    int _armor{0};
};

class DamageOverTimeEffect : public Effect {
public:
    DamageOverTimeEffect(Character &caster, Character& target, int turns, int damage) : Effect(caster, target, turns), _damage(damage) {}

    void apply_turn(int turn) override;
private:
    int _damage{0};
};

class RechargeManaEffect : public Effect {
public:
    RechargeManaEffect(Character &caster, Character& target, int turns, int amount) : Effect(caster, target, turns), _amount(amount) {}

    void apply_turn(int turn) override;

private:
    int _amount{0};
};

#endif
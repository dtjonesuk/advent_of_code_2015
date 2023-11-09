
#include "Effect.h"
#include

Effect::Effect(Character &target, int turns) : _turns(turns), _turns_left(turns), _target(target) {

}

Effect::~Effect() {

}

bool Effect::is_instant() const {
    return (_turns == 0);
}

bool Effect::apply() {
    apply_turn(_turns_left);
    --_turns_left;
    return _turns_left > 0;
}

void Effect::apply_turn(int turn) {

}

void InstantDamageEffect::apply_turn(int turn) {
    _target.apply_damage(_damage);
}

void InstantDrainEffect::apply_turn(int turn) {
    _target.apply_damage(_amount);
    _caster.apply_healing(_amount);
}

void ShieldEffect::apply_turn(int turn) {
    _target.apply_armor(_armor);
}

void DamageOverTimeEffect::apply_turn(int turn) {
    _target.apply_damage(_damage);
}

void RechargeManaEffect::apply_turn(int turn) {
    _target.apply_mana(_amount);
}

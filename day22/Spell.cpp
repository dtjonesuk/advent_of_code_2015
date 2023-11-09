//
// Created by David on 06/11/2023.
//

#include "Spell.h"


Spell::Spell(Character &caster, std::string name, int cost) : _caster(caster), _name(name), _cost(cost) {

}

Spell::~Spell() {

}


Effect *MagicMissileSpell::cast(Character &target) {
    return new InstantDamageEffect(_caster, target, 4);
}

Effect *DrainSpell::cast(Character &target) {
    return new InstantDrainEffect(_caster, target, 2);
}

Effect *ShieldSpell::cast(Character &target) {
    return nullptr;
}

Effect *PoisonSpell::cast(Character &target) {
    return nullptr;
}

Effect *RechargeSpell::cast(Character &target) {
    return nullptr;
}

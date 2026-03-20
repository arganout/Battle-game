#pragma once
#include "character.h"

class Mage : public Character {
private:
    int mana;
    int maxMana;

public:
    Mage(string name);

    int  normalAttack()  override;
    int  heavyAttack()   override;
    int  specialAttack() override;  // Fireball — 2x damage costs mana
    void showSpecialInfo() override;

    int  getMana();
    void showStats();
};
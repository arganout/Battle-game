#pragma once
#include "character.h"

class Archer : public Character {
public:
    Archer(string name);

    int  normalAttack()  override;
    int  heavyAttack()   override;
    int  specialAttack() override;  // Double Shot — attacks twice
    void showSpecialInfo() override;
};
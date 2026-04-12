#pragma once
#include "character.h"

class Warrior : public Character {
public:
    Warrior(string name);

    int  normalAttack()  override;
    int  heavyAttack()   override;
    int  specialAttack() override;  // Shield Bash — stuns 1 turn
    void showSpecialInfo() override;
};
#include "../include/mage.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

Mage::Mage(string name)
    : Character(name, 80, 50, 3) {
    mana    = 100;
    maxMana = 100;
}

int Mage::normalAttack() {
    int dice   = rollDice();
    float mult = getDiceMultiplier(dice);
    int damage = (int)(attackPower * mult);
    printDice(dice);
    cout << "  [MAGIC BOLT] " << name 
         << " fires for " << damage << " damage!\n";
    return damage;
}

int Mage::heavyAttack() {
    if (mana < 20) {
        cout << "  Not enough mana!\n";
        return 0;
    }
    int dice   = rollDice();
    float mult = getDiceMultiplier(dice);
    int damage = (int)(attackPower * 1.5f * mult);
    mana -= 20;
    printDice(dice);
    cout << "  [THUNDER] " << name 
         << " strikes for " << damage << " damage! (Mana: " << mana << ")\n";
    return damage;
}

int Mage::specialAttack() {
    if (specialUses <= 0) {
        cout << "  No special uses left!\n";
        return 0;
    }
    if (mana < 40) {
        cout << "  Not enough mana for Fireball!\n";
        return 0;
    }
    specialUses--;
    mana -= 40;
    int damage = attackPower * 2;
    cout << "  [FIREBALL] " << name 
         << " explodes for " << damage 
         << " damage! (Mana: " << mana << ")\n";
    return damage;
}

void Mage::showSpecialInfo() {
    cout << "  Special: Fireball — 2x damage costs 40 mana (" 
         << specialUses << " uses)\n";
    cout << "  Mana: " << mana << "/" << maxMana << "\n";
}

int Mage::getMana() { return mana; }
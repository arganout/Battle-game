#include "../include/archer.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

Archer::Archer(string name)
    : Character(name, 110, 35, 3) {}

int Archer::normalAttack() {
    int dice   = rollDice();
    float mult = getDiceMultiplier(dice);
    int damage = (int)(attackPower * mult);
    printDice(dice);
    cout << "  [ARROW] " << name 
         << " shoots for " << damage << " damage!\n";
    return damage;
}

int Archer::heavyAttack() {
    int dice   = rollDice();
    float mult = getDiceMultiplier(dice);
    int damage = (int)(attackPower * 1.8f * mult);
    printDice(dice);
    cout << "  [POWER SHOT] " << name 
         << " fires for " << damage << " damage!\n";
    return damage;
}

int Archer::specialAttack() {
    if (specialUses <= 0) {
        cout << "  No special uses left!\n";
        return 0;
    }
    specialUses--;
    int dice1   = rollDice();
    int dice2   = rollDice();
    int damage1 = (int)(attackPower * getDiceMultiplier(dice1));
    int damage2 = (int)(attackPower * getDiceMultiplier(dice2));
    int total   = damage1 + damage2;
    cout << "  [DOUBLE SHOT] Shot 1: " << damage1 
         << "  Shot 2: " << damage2 
         << "  Total: " << total << "\n";
    return total;
}

void Archer::showSpecialInfo() {
    cout << "  Special: Double Shot — two arrows in one turn (" 
         << specialUses << " uses)\n";
}
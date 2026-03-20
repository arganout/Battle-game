#include "../include/warrior.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string name)
    : Character(name, 150, 30, 3) {}

int Warrior::normalAttack() {
    int dice   = rollDice();
    float mult = getDiceMultiplier(dice);
    int damage = (int)(attackPower * mult);
    printDice(dice);
    cout<< "  [SLASH] " << name << " slashes for " << damage << " damage!\n";
    return damage;
}

int Warrior::heavyAttack() {
    int dice = rollDice();
    if (dice <= 3) {
        cout << "  [HEAVY] " << name << " missed the heavy attack!\n";
        return 0;
    }
    int damage = (int)(attackPower * 2 * getDiceMultiplier(dice));
    printDice(dice);
    cout << "  [HEAVY] " << name << " smashes for " << damage << " damage!\n";
    return damage;
}

int Warrior::specialAttack() {
    if (specialUses <= 0) {
        cout << "  No special uses left!\n";
        return 0;
    }
    specialUses--;
    int damage = attackPower;
    cout << "  [SHIELD BASH] " << name 
         << " bashes for " << damage << " damage + stun!\n";
    return damage;
}

void Warrior::showSpecialInfo() {
    cout << "  Special: Shield Bash — stuns monster 1 turn (" 
         << specialUses << " uses)\n";
}
#include "../include/monster.h"
#include "../include/utils.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Monster::Monster(string name, int health, int attackPower) {
    this->name        = name;
    this->health      = health;
    this->maxHealth   = health;
    this->attackPower = attackPower;
    this->stunned     = false;
}

int Monster::attack() {
    if (stunned) {
        cout << "  [STUN] " << name << " is stunned and cannot attack!\n";
        stunned = false;
        return 0;
    }
    int dice   = rollDice();
    float mult = getDiceMultiplier(dice);
    int damage = (int)(attackPower * mult);
    printDice(dice);
    cout << "  [" << name << "] attacks for " << damage << " damage!\n";
    return damage;
}

void Monster::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    cout << "  [" << name << "] takes " 
         << damage << " damage! HP: " << health << "\n";
}

void Monster::stun()             { stunned  = true;       }
string Monster::getName()        { return name;           }
int    Monster::getHealth()      { return health;         }
int    Monster::getMaxHealth()   { return maxHealth;      }
bool   Monster::isAlive()        { return health > 0;     }
bool   Monster::isStunned()      { return stunned;        }

void Monster::showStats() {
    cout << "\n";
    showHPBar(name, health, maxHealth);
}
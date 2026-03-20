#include "../include/character.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

Character::Character(string name, int health, 
                     int attackPower, int specialUses)
    : inventory(5) {
    this->name              = name;
    this->health            = health;
    this->maxHealth         = health;
    this->attackPower       = attackPower;
    this->specialUses       = specialUses;
    this->shieldActive      = false;
    this->powerCrystalTurns = 0;
}

void Character::takeDamage(int damage) {
    if (shieldActive) {
        cout << "  [SHIELD] " << name << " blocked the attack!\n";
        shieldActive = false;
        return;
    }
    health -= damage;
    if (health < 0) health = 0;
}

void Character::heal(int amount) {
    health += amount;
    if (health > maxHealth) health = maxHealth;
    cout << "  [HEAL] " << name << " restored " << amount << " HP!\n";
}

void Character::activateShield() {
    shieldActive = true;
    cout << "  [SHIELD] " << name << " raised a shield!\n";
}

void Character::activatePowerCrystal() {
    attackPower       += 10;
    powerCrystalTurns  = 3;
    cout << "  [POWER] Attack +10 for 3 turns!\n";
}

void Character::reducePowerCrystalTurns() {
    if (powerCrystalTurns > 0) {
        powerCrystalTurns--;
        if (powerCrystalTurns == 0) {
            attackPower -= 10;
            cout << "  [POWER] Power Crystal wore off.\n";
        }
    }
}

bool Character::useItem(int index) {
    if (index < 0 || index >= inventory.getItemCount()) {
        cout << "  Invalid item!\n";
        return false;
    }
    Item item = inventory.getItem(index);
    switch (item.getType()) {
        case HEALTH_POTION:
            heal(item.getValue());
            break;
        case SHIELD:
            activateShield();
            break;
        case POWER_CRYSTAL:
            activatePowerCrystal();
            break;
        case ELIXIR:
            heal(maxHealth);
            break;
    }
    inventory.removeItem(index);
    return true;
}

void Character::addItem(Item item) {
    inventory.addItem(item);
}

void Character::showStats() {
    printLine();
    cout << "  Name    : " << name        << "\n";
    cout << "  Attack  : " << attackPower << "\n";
    cout << "  Special : " << specialUses << " uses left\n";
    showHPBar(name, health, maxHealth);
    printLine();
}

void Character::showInventoryMenu() {
    inventory.showInventory();
}

string Character::getName()        { return name;          }
int    Character::getHealth()      { return health;        }
int    Character::getMaxHealth()   { return maxHealth;     }
int    Character::getAttackPower() { return attackPower;   }
int    Character::getSpecialUses() { return specialUses;   }
bool   Character::isAlive()        { return health > 0;    }
bool   Character::isShieldActive() { return shieldActive;  }
Inventory &Character::getInventory(){ return inventory;    }
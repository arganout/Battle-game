#pragma once
#include "inventory.h"
#include <string>
using namespace std;

class Monster;  // forward declaration

class Character {
protected:
    string    name;
    int       health;
    int       maxHealth;
    int       attackPower;
    int       specialUses;
    bool      shieldActive;
    int       powerCrystalTurns;
    Inventory inventory;

public:
    Character(string name, int health, int attackPower, int specialUses);

    // actions
    virtual int  normalAttack()  = 0;   // pure virtual
    virtual int  heavyAttack()   = 0;   // pure virtual
    virtual int  specialAttack() = 0;   // pure virtual
    virtual void showSpecialInfo() = 0; // pure virtual

    void takeDamage(int damage);
    void heal(int amount);
    void activateShield();
    void activatePowerCrystal();
    void reducePowerCrystalTurns();
    bool useItem(int index);
    void addItem(Item item);
    void showStats();
    void showInventoryMenu();

    // getters
    string getName();
    int    getHealth();
    int    getMaxHealth();
    int    getAttackPower();
    int    getSpecialUses();
    bool   isAlive();
    bool   isShieldActive();
    Inventory& getInventory();
};
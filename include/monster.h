#pragma once
#include <string>
using namespace std;

class Character;

class Monster {
private:
    string name;
    int    health;
    int    maxHealth;
    int    attackPower;
    bool   stunned;

public:
    Monster(string name, int health, int attackPower);

    int  attack();
    void takeDamage(int damage);
    void stun();
    void showStats();

    string getName();
    int    getHealth();
    int    getMaxHealth();
    bool   isAlive();
    bool   isStunned();
};
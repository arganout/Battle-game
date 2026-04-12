#pragma once
#include "character.h"
#include "monster.h"
using namespace std;

class Battle {
private:
    Character* player;
    Monster*   monster;
    int        round;
    bool       monsterStunned;

public:
    Battle(Character* player, Monster* monster);

    void    showBattleStatus();
    int     getPlayerChoice();
    bool    runRound();
    bool    runBattle();
};
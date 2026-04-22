#include "../include/battle.h"
#include "../include/utils.h"
#include <iostream>
using namespace std;

Battle::Battle(Character* player, Monster* monster) 
    : player(player), monster(monster), round(1), monsterStunned(false) {
}

// Mark as const because this function doesn't change the Battle state
void Battle::showBattleStatus() const {
    clearScreen();
    printLine();
    cout << "  Round " << round << "\n";
    printLine();
    
    // Explicitly check for nullptr before using pointers
    if (player && monster) {
        showHPBar(player->getName(), player->getHealth(), player->getMaxHealth());
        showHPBar(monster->getName(), monster->getHealth(), monster->getMaxHealth());
    }
    printLine();
}

int Battle::getPlayerChoice() {
    cout << "\n  What will you do?\n";
    cout << "  [1] Normal Attack\n";
    cout << "  [2] Heavy Attack  (50% miss but 2x damage)\n";
    cout << "  [3] Special Move  (" 
         << player->getSpecialUses() << " uses left)\n";
    cout << "  [4] Use Item\n";
    cout << "\n  Your choice: ";

    int choice;
    cin >> choice;
    return choice;
}

bool Battle::runRound() {
    showBattleStatus();

    int choice  = getPlayerChoice();
    int damage  = 0;
    bool stunned = false;

    // player action
    switch (choice) {
        case 1:
            damage = player->normalAttack();
            break;
        case 2:
            damage = player->heavyAttack();
            break;
        case 3:
            damage = player->specialAttack();
            stunned = true;  // warrior bash stuns
            break;
        case 4:
            player->showInventoryMenu();
            if (player->getInventory().hasItems()) {
                cout << "  Choose item number: ";
                int itemChoice;
                cin >> itemChoice;
                player->useItem(itemChoice - 1);
            }
            round++;
            return monster->isAlive();
        default:
            cout << "  Invalid choice! Turn skipped.\n";
    }

    // apply damage to monster
    if (damage > 0) {
        monster->takeDamage(damage);
        if (stunned && choice == 3) {
            monster->stun();
        }
    }

    // check if monster died
    if (!monster->isAlive()) {
        showBattleStatus();
        cout << "\n  [WIN] " << monster->getName() 
             << " has been defeated!\n";
        return false;
    }

    // monster attacks back
    cout << "\n  --- " << monster->getName() 
         << "'s turn ---\n";
    int monsterDamage = monster->attack();
    if (monsterDamage > 0) {
        player->takeDamage(monsterDamage);
    }

    // reduce power crystal turns
    player->reducePowerCrystalTurns();

    // check if player died
    if (!player->isAlive()) {
        showBattleStatus();
        cout << "\n  [LOSE] " << player->getName() 
             << " has fallen!\n";
        return false;
    }

    round++;
    waitForEnter();
    return true;
}

bool Battle::runBattle() {
    while (player->isAlive() && monster->isAlive()) {
        bool ongoing = runRound();
        if (!ongoing) break;
    }
    return player->isAlive();
}
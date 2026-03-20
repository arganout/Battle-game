#include <windows.h>

// 2. Standard C++ libraries second
#include <iostream>
#include <cstdlib>
#include <ctime>

// 3. Your custom headers third 
#include "include/warrior.h"
#include "include/mage.h"
#include "include/archer.h"
#include "include/monster.h"
#include "include/battle.h"
#include "include/utils.h"
#include "include/inventory.h"
using namespace std;

// choose character
Character* chooseCharacter() {
    //clearScreen();
    printLine();
    cout << "    CHOOSE YOUR CHARACTER\n";
    printLine();
    cout << "  [1] Warrior  - HP: 150  ATK: 30  Special: Shield Bash\n";
    cout << "  [2] Mage     - HP: 80   ATK: 50  Special: Fireball\n";
    cout << "  [3] Archer   - HP: 110  ATK: 35  Special: Double Shot\n";
    printLine();
    cout << "  Enter your name: ";
    string name;
    cin >> name;

    cout << "  Choose character [1-3]: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: return new Warrior(name);
        case 2: return new Mage(name);
        case 3: return new Archer(name);
        default:
            cout << "  Invalid! Defaulting to Warrior.\n";
            return new Warrior(name);
    }
}

// run a wave
bool runWave(Character* player, 
             string monsterName, 
             int monsterHP, 
             int monsterATK,
             int waveNumber) {
    //clearScreen();
    printLine();
    cout << "  WAVE " << waveNumber << " — " << monsterName << " appears!\n";
    printLine();
    cout << "  " << monsterName 
         << "  HP: " << monsterHP 
         << "  ATK: " << monsterATK << "\n";
    waitForEnter();

    Monster monster(monsterName, monsterHP, monsterATK);
    Battle  battle(player, &monster);
    return  battle.runBattle();
}

int main() {
    std::system("chcp 65001 > nul"); // Added std:: here
    srand(time(0));  // seed random

    // title screen
    //clearScreen();
    printLine();
    cout << "         BATTLE GAME\n";
    cout << "    Turn Based RPG in C++\n";
    printLine();
    waitForEnter();

    // choose character
    Character* player = chooseCharacter();

    // show character stats
    //clearScreen();
    printLine();
    cout << "  Your character:\n";
    player->showStats();
    player->showSpecialInfo();
    waitForEnter();

    // === WAVE 1 — Goblin ===
    if (!runWave(player, "Goblin", 60, 12, 1)) {
        cout << "\n  GAME OVER! Better luck next time.\n";
        delete player;
        std::system("pause"); // <--- Added pause here
        return 0;
    }

    // item drop after wave 1
    Inventory inv(1);
    Item drop1 = inv.getRandomDrop();
    cout << "\n  Item dropped: ";
    drop1.showInfo();
    player->addItem(drop1);
    waitForEnter();

    // === WAVE 2 — Orc ===
    if (!runWave(player, "Orc", 100, 20, 2)) {
        cout << "\n  GAME OVER! Better luck next time.\n";
        delete player;
        std::system("pause"); // <--- Added pause here
        return 0;
    }

    // item drop after wave 2
    Item drop2 = inv.getRandomDrop();
    cout << "\n  Item dropped: ";
    drop2.showInfo();
    player->addItem(drop2);
    waitForEnter();

    // === WAVE 3 — Troll ===
    if (!runWave(player, "Troll", 140, 28, 3)) {
        cout << "\n  GAME OVER! Better luck next time.\n";
        delete player;
        std::system("pause"); // <--- Added pause here
        return 0;
    }

    // item drop after wave 3
    Item drop3 = inv.getRandomDrop();
    cout << "\n  Item dropped: ";
    drop3.showInfo();
    player->addItem(drop3);
    waitForEnter();

    // === BOSS — Dragon ===
    //clearScreen();
    printLine();
    cout << "  *** FINAL BOSS ***\n";
    cout << "  THE DRAGON AWAKENS!\n";
    printLine();
    cout << "  Dragon  HP: 250  ATK: 45\n";
    cout << "  This is your final challenge!\n";
    waitForEnter();

    if (!runWave(player, "Dragon", 250, 45, 4)) {
        cout << "\n  GAME OVER! The Dragon was too powerful.\n";
        delete player;
        std::system("pause"); // <--- Added pause here
        return 0;
    }

    // victory screen
    //clearScreen();
    printLine();
    cout << "  *** VICTORY! ***\n";
    cout << "  " << player->getName() 
         << " defeated the Dragon!\n";
    cout << "  You are the champion!\n";
    printLine();
    player->showStats();

    delete player;
    std::system("pause"); // <--- Kept pause here for victory
    return 0;
}
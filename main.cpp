#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <string>

#include "include/warrior.h"
#include "include/mage.h"
#include "include/archer.h"
#include "include/monster.h"
#include "include/battle.h"
#include "include/utils.h"
#include "include/inventory.h"

// ---------------------------------------------------------------------------
// Cross-platform pause — replaces system("pause") and system("chcp 65001")
// ---------------------------------------------------------------------------
void waitForEnterModern() {
    std::cout << "\n  Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// ---------------------------------------------------------------------------
// chooseCharacter
// Returns unique_ptr — caller owns the Character, no manual delete needed
// ---------------------------------------------------------------------------
std::unique_ptr<Character> chooseCharacter() {
    printLine();
    std::cout << "    CHOOSE YOUR CHARACTER\n";
    printLine();
    std::cout << "  [1] Warrior  - HP: 150  ATK: 30  Special: Shield Bash\n";
    std::cout << "  [2] Mage     - HP: 80   ATK: 50  Special: Fireball\n";
    std::cout << "  [3] Archer   - HP: 110  ATK: 35  Special: Double Shot\n";
    printLine();

    std::cout << "  Enter your name: ";
    std::string name;
    std::cin >> name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "  Choose character [1-3]: ";
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1:  return std::make_unique<Warrior>(name);
        case 2:  return std::make_unique<Mage>(name);
        case 3:  return std::make_unique<Archer>(name);
        default:
            std::cout << "  Invalid! Defaulting to Warrior.\n";
            return std::make_unique<Warrior>(name);
    }
}

// ---------------------------------------------------------------------------
// runWave
// Takes raw Character* — borrows the pointer, does NOT own it
// Caller (main) retains ownership via unique_ptr
// ---------------------------------------------------------------------------
bool runWave(Character* player,
             const std::string& monsterName,
             int monsterHP,
             int monsterATK,
             int waveNumber)
{
    printLine();
    std::cout << "  WAVE " << waveNumber << " - " << monsterName << " appears!\n";
    printLine();
    std::cout << "  " << monsterName
              << "  HP: "  << monsterHP
              << "  ATK: " << monsterATK << "\n";
    waitForEnter();

    Monster monster(monsterName, monsterHP, monsterATK);
    Battle  battle(player, &monster);
    return  battle.runBattle();
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main() {
    // Seed the random engine once here — pass it down if your battle/utils
    // need randomness, instead of using global srand/rand
    std::mt19937 rng(std::random_device{}());

    // Title screen
    printLine();
    std::cout << "         BATTLE GAME\n";
    std::cout << "    Turn Based RPG in C++\n";
    printLine();
    waitForEnterModern();

    // Choose character — unique_ptr manages lifetime automatically
    std::unique_ptr<Character> player = chooseCharacter();

    // Show character stats
    printLine();
    std::cout << "  Your character:\n";
    player->showStats();
    player->showSpecialInfo();
    waitForEnterModern();

    // Inventory for item drops
    Inventory inv(1);

    // === WAVE 1 - Goblin ===
    if (!runWave(player.get(), "Goblin", 60, 12, 1)) {
        std::cout << "\n  GAME OVER! Better luck next time.\n";
        waitForEnterModern();
        return 0;   // unique_ptr auto-deletes player here
    }

    Item drop1 = inv.getRandomDrop();
    std::cout << "\n  Item dropped: ";
    drop1.showInfo();
    player->addItem(drop1);
    waitForEnterModern();

    // === WAVE 2 - Orc ===
    if (!runWave(player.get(), "Orc", 100, 20, 2)) {
        std::cout << "\n  GAME OVER! Better luck next time.\n";
        waitForEnterModern();
        return 0;
    }

    Item drop2 = inv.getRandomDrop();
    std::cout << "\n  Item dropped: ";
    drop2.showInfo();
    player->addItem(drop2);
    waitForEnterModern();

    // === WAVE 3 - Troll ===
    if (!runWave(player.get(), "Troll", 140, 28, 3)) {
        std::cout << "\n  GAME OVER! Better luck next time.\n";
        waitForEnterModern();
        return 0;
    }

    Item drop3 = inv.getRandomDrop();
    std::cout << "\n  Item dropped: ";
    drop3.showInfo();
    player->addItem(drop3);
    waitForEnterModern();

    // === BOSS - Dragon ===
    printLine();
    std::cout << "  *** FINAL BOSS ***\n";
    std::cout << "  THE DRAGON AWAKENS!\n";
    printLine();
    std::cout << "  Dragon  HP: 250  ATK: 45\n";
    std::cout << "  This is your final challenge!\n";
    waitForEnterModern();

    if (!runWave(player.get(), "Dragon", 250, 45, 4)) {
        std::cout << "\n  GAME OVER! The Dragon was too powerful.\n";
        waitForEnterModern();
        return 0;
    }

    // Victory screen
    printLine();
    std::cout << "  *** VICTORY! ***\n";
    std::cout << "  " << player->getName() << " defeated the Dragon!\n";
    std::cout << "  You are the champion!\n";
    printLine();
    player->showStats();
    waitForEnterModern();

    return 0;   // unique_ptr auto-deletes player here too
}
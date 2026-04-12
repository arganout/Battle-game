#include "../include/inventory.h"
#include <iostream>
#include <cstdlib>
#include <iterator>
using namespace std;

Inventory::Inventory(int maxSize) {
    this->maxSize = maxSize;
}

bool Inventory::addItem(Item item) {
    if (items.size() >= maxSize) {
        cout << "  Inventory full!\n";
        return false;
    }
    items.push_back(item);
    cout << "  [+] " << item.getName() << " added to inventory!\n";
    return true;
}

void Inventory::showInventory() {
    if (items.empty()) {
        cout << "  Inventory is empty.\n";
        return;
    }
    cout << "\n=== Inventory ===\n";
    for (int i = 0; i < items.size(); i++) {
        cout << "  [" << i + 1 << "] ";
        items[i].showInfo();
    }
    cout << "=================\n";
}

bool Inventory::hasItems()     { return !items.empty();  }
int  Inventory::getItemCount() { return items.size();    }

Item Inventory::getItem(int index) {
    return items[index];
}

void Inventory::removeItem(int index) {
    items.erase(items.begin() + index);
}

Item Inventory::getRandomDrop() {
    int roll = rand() % 4;
    if (roll == 0) return Item("Health Potion", "Restores 40 HP",         HEALTH_POTION,  40);
    if (roll == 1) return Item("Shield",        "Blocks next attack",      SHIELD,         1);
    if (roll == 2) return Item("Power Crystal", "+10 attack for 3 turns",  POWER_CRYSTAL,  10);
    return             Item("Elixir",           "Fully restores HP (rare)", ELIXIR,         999);
}
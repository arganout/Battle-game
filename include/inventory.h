#pragma once
#include "item.h"
#include <vector>
using namespace std;

class Inventory {
private:
    vector<Item> items;
    int          maxSize;

public:
    Inventory(int maxSize = 5);

    bool addItem(Item item);
    void showInventory();
    bool hasItems();
    int  getItemCount();
    Item getItem(int index);
    void removeItem(int index);

    // random item drop after wave win
    Item getRandomDrop();
};
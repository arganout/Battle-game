#pragma once
#include <string>
using namespace std;

enum ItemType {
    HEALTH_POTION,
    SHIELD,
    POWER_CRYSTAL,
    ELIXIR
};

class Item {
private:
    string   name;
    string   description;
    ItemType type;
    int      value;

public:
    Item(string name, string description, ItemType type, int value);

    string   getName();
    string   getDescription();
    ItemType getType();
    int      getValue();
    void     showInfo();
};
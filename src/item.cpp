#include "../include/item.h"
#include <iostream>
using namespace std;

Item::Item(string name, string description, ItemType type, int value) {
    this->name        = name;
    this->description = description;
    this->type        = type;
    this->value       = value;
}

string   Item::getName()        { return name;        }
string   Item::getDescription() { return description; }
ItemType Item::getType()        { return type;        }
int      Item::getValue()       { return value;       }

void Item::showInfo() {
    cout << "  [" << name << "] - " << description << "\n";
}
#include "../include/utils.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice() {
    return (rand() % 6) + 1;
}

float getDiceMultiplier(int dice) {
    if (dice <= 2) return 0.5f;
    if (dice <= 4) return 1.0f;
    if (dice == 5) return 1.5f;
    return 2.0f;  // dice == 6 critical
}

void printDice(int dice) {
    cout << "\n  Dice rolled: " << dice;
    if (dice <= 2)      cout << "  (Weak hit - 0.5x)\n";
    else if (dice <= 4) cout << "  (Normal hit - 1.0x)\n";
    else if (dice == 5) cout << "  (Strong hit - 1.5x)\n";
    else                cout << "  *** CRITICAL HIT - 2.0x ***\n";
}

void showHPBar(string name, int current, int max) {
    int barLength = 20;
    int filled = (current * barLength) / max;
    if (filled < 0) filled = 0;

    cout << "  " << name;

    // padding for alignment
    for (int i = name.length(); i < 10; i++) cout << " ";

    cout << " [";
    for (int i = 0; i < barLength; i++) {
        if (i < filled) cout << "#";
        else            cout << "-";
    }
    cout << "] " << current << "/" << max << " HP\n";
}

void printLine() {
    cout << "================================\n";
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void clearScreen() {
    system("cls");
}
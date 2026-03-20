#pragma once
#include <string>
using namespace std;

// dice roll 1-6
int rollDice();

// damage multiplier based on dice
float getDiceMultiplier(int dice);

// print dice result
void printDice(int dice);

// display HP bar
void showHPBar(string name, int current, int max);

// display separator line
void printLine();

// pause and wait for enter
void waitForEnter();

// clear screen
void clearScreen();
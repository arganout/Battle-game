# Battle Game — C++ RPG

A turn-based RPG battle game built in C++ using OOP concepts.

## Characters
- Warrior — High HP, Shield Bash special
- Mage    — High damage, Fireball spell  
- Archer  — Balanced, Double Shot special

## Features
- Choose your character
- Turn based combat with dice system
- Multiple monster waves
- Inventory and item drops
- HP bar display
- Special moves and spells
- Boss fight (Dragon) at the end

## How to Compile and Run
g++ main.cpp src/utils.cpp src/item.cpp src/inventory.cpp
src/character.cpp src/warrior.cpp src/mage.cpp src/archer.cpp
src/monster.cpp src/battle.cpp -o game.exe

## OOP Concepts Used
- Classes and Objects
- Inheritance
- Polymorphism
- Encapsulation
- Composition

## Project Structure
Game/
├── include/    header files (.h)
├── src/        implementation files (.cpp)
└── main.cpp    entry point
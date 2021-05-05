//
// Created by Codie Cottrell on 2/28/21.
//
#include "Player.h"
#include <utility>

//default constructor
Player::Player() {
    this->name = "Sir Nigel";
    setHp(100);
    setInteractive(true);
    updateLocation({0},{0});
}

Player::Player(string name) : name(std::move(name)) {
    setHp(100);
    setInteractive(true);
    updateLocation({0},{0});
}

//simple constructor using an existing inventory
Player::Player(string name, int hp, Inventory inventory, const vector<double>& x, const vector<double>& y) : name(std::move(name)), inventory(std::move(inventory)) {
    setHp(hp);
    setInteractive(true);
    updateLocation(x,y);
}

void Player::move(double newxCoordinate, double newyCoordinate){
    updateLocation({newxCoordinate}, {newyCoordinate});
}

//item interaction
void Player::interactItem(Item* item) {
    if (item->getInteractive()) {
        item->interact();
        inventory.addTo(item);
    }
}

// NPC interaction
void Player::interactNPC(NPC* npc){
    if (npc->getInteractive()) {
        npc->interact();
    } else {
        cout << "leave me alone" << endl;
    }
}








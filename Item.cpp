// Item class file
//Author: Codie Cottrell
#include <iostream>
#include "Item.h"
using namespace std;

Item::Item() : rarity(0), worth(0){ }

Item::Item(const string& name, int rarity, int worth) : rarity(rarity), worth(worth){ }

int Item::getRarity() const {
    return rarity;
}

int Item::getWorth() const {
    return worth;
}

string Item::toString() {
    return "item: " + name + "rarity: " + to_string(rarity) + "worth: " + to_string(worth);
}

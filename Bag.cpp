//
// Created by Codie Cottrell on 10/19/20.
//
#include <iostream>
#include <vector>
#include "Item.h"
#include "Bag.h"
using namespace std;

Bag::Bag() {
    size = 10;
    durability = 1;
}

vector<Item> Bag::viewBag() {
    for (Item item: bag){
        cout << item.toString() << endl;
    }
}
void Bag::addToBag(const Item& itemToAdd) {
    bag.push_back(itemToAdd);
}
Item Bag::getFromBag(int itemLocation) {
    cout << bag[itemLocation].toString() << endl;
}

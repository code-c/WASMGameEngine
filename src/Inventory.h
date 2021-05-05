//
// Created by Codie Cottrell on 2/28/21.
//

#ifndef FERNQUEST_INVENTORY_H
#define FERNQUEST_INVENTORY_H

#include "Item.h"
#include <vector>
#include <iostream>
using namespace std;

class Inventory {
private:
    std::vector<Item*> inventory;

public:
    Inventory();
    void showInventory();
    void addTo(Item* newItem);
    Item* takeItem(int itemSlot);

};


#endif //FERNQUEST_INVENTORY_H

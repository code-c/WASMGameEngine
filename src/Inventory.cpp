//
// Created by Codie Cottrell on 2/28/21.
//

#include "Inventory.h"
#include "Bridge.h"

//constructor
Inventory::Inventory() {}

//add an item to the inventory
void Inventory::addTo(Item* newItem) {
    inventory.push_back(newItem);
}

//show what the inventory contains
void Inventory::showInventory() {
    int size = inventory.size();
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            Item *item = inventory.at(i);
            cout << to_string(i) << ": " << item->getName() << endl;
        }
    } else {
        cout << "there is nothing in your inventory at this time." << endl;
    }
}

//take something out of the inventory
Item* Inventory::takeItem(int itemSlot) {
    Item* itemToUse = inventory.at(itemSlot);
    inventory.erase(inventory.begin()+itemSlot);
    return itemToUse;
}

//testing main for invetory
//int main (){
//    Inventory inventory;
//    Bridge* bridge = new Bridge();
//    inventory.addTo(bridge);
//    inventory.showInventory();
//    int itemNum;
//    cout << "select the item to be used" << endl;
//    cin >> itemNum;
//    cout << inventory.takeItem(itemNum)->toString() << endl;
//    inventory.showInventory();
//}
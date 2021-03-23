//
// Created by Codie Cottrell on 2/28/21.
//

#include "Chest.h"

Chest::Chest(Item chestItem) : chestItem(chestItem){}

Item Chest::open(Key key){
    int keyType = key.checkKey();
    if(keyType == type){
        return chestItem;
    }
    else{
        cout << "sorry this key doesnt work on a chest" << endl;
    }
}
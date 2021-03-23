//
// Created by Codie Cottrell on 2/28/21.
//

#ifndef FERNQUEST_CHEST_H
#define FERNQUEST_CHEST_H

#include "Entity.h"
#include "Key.h"
#include "Item.h"
#include <iostream>
using namespace std;

class Chest : Entity {
private:
    static const int type{0};
    Item chestItem;

public:
    Chest(Item chestItem);

    Item open(Key key);


};

#endif //FERNQUEST_CHEST_H

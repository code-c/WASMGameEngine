//
// Created by Codie Cottrell on 2/28/21.
//

#ifndef FERNQUEST_NPC_H
#define FERNQUEST_NPC_H

#include "Entity.h"
#include "Item.h"
class NPC : public Entity {
private:
    Item itemDrop;
    std::string nameRequiredItem;

public:
    NPC();
    NPC(Item item);
    void interact();
    Item interact(Item item);
};


#endif //FERNQUEST_NPC_H

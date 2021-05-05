//
// Created by Codie Cottrell on 2/28/21.
//

#include "NPC.h"
NPC::NPC() {}

NPC::NPC(Item item) : itemDrop(item){}

void NPC::interact() {}

Item NPC::interact(Item item) {
    if (nameRequiredItem == item.getName()){

    }
}

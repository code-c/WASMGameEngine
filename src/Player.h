//
// Created by Codie Cottrell on 2/28/21.
//

#ifndef FERNQUEST_PLAYER_H
#define FERNQUEST_PLAYER_H

#include "Entity.h"
#include "QuestLog.h"
#include "Inventory.h"
#include "NPC.h"
#include <string>

class Player : public Entity {
public:
    std::string name;
    Inventory inventory;
    Item itemHeld;
    //QuestLog questLog; till we fix quest log

    Player();
    Player(std::string name);
    Player(string name, int hp, Inventory inventory,const vector<double>& x,const vector<double>& y);
    void move(double xCoordinate, double yCoordinate);

    void interactItem(Item* item);
    void interactNPC(NPC* npc);

};


#endif //FERNQUEST_PLAYER_H

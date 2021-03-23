// Item class header
// Author: Codie Cottrell
#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item: public Entity{
private:
    int value;
    int type; //weapon, utility, food, material
    std::string name;
public:
    Item(); // generic constructor
    Item(std::string  name, int value, int type); // constructor for specific items. (eventually we will import item stats.)

    //setters
    void setValue(int value);
    void setType(int type);
    void setName(const std::string &name);

    //getters
    int getValue() const;
    int getType() const;
    std::string getName() const;

    //debug
    std::string toString();
};

#endif

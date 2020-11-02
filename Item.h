// Item class header
// Author: Codie Cottrell
#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    int rarity;
    int worth;
    std::string name;
public:
    Item(); // generic constructor
    Item(const std::string& name, int rarity, int worth); // constructor for specific items. (eventually we will import item stats.)

    int getRarity() const;
    int getWorth() const;
    std::string toString();
};

#endif

//
// Created by Codie Cottrell on 10/19/20.
//

#ifndef FERNQUEST_BAG_H
#define FERNQUEST_BAG_H

class Bag {
private:
    int size;
    std::vector<Item> bag ;
    int durability;
public:
    Bag();
    std::vector<Item> viewBag();
    void addToBag(const Item& itemToAdd);
    Item getFromBag(int itemLocation);

};


#endif //FERNQUEST_BAG_H

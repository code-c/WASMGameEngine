// Item class file
//Author: Codie Cottrell
#include <iostream>
#include <utility>
#include "Item.h"
using namespace std;

//default constructor
Item::Item() : name(""), value(0), type(0){ }

Item::Item(string name, int value, int type) : name(std::move(name)), value(value), type(type) { }

//getters and setters

void Item::setValue(int value){
    Item::value = value;
}
void Item::setType(int type) {
    Item::type = type;
}

void Item::setName(const string &name) {
    Item::name = name;
}

string Item::getName() const {
    return name;
}

int Item::getValue() const {
    return value;
}

int Item::getType() const {
    return type;
}

string Item::toString() {
    // convert type value to strings
    string typeString;
    switch (type) {
        case 0:
            typeString = "none";
            break;
        case 1:
            typeString = "weapon";
            break;
        case 2:
            typeString = "utility";
            break;
        case 3:
            typeString = "food";
            break;
        case 4:
            typeString = "material";
            break;
        default:
            typeString = "none";
            break;
    }
    //
    return "item: " + name + "\nvalue: " + to_string(value) + "\ntype: " + typeString;
}

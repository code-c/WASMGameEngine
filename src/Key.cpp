//
// Created by Codie Cottrell on 2/27/21.
//
#include "Key.h"

//constructor for key
Key::Key(int type) : type(type), used(false){}

int Key::checkKey() const{
    return type;
}
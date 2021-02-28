//
// Created by Codie Cottrell on 2/27/21.
//

#ifndef FERNQUEST_KEY_H
#define FERNQUEST_KEY_H

#include "Entity.h"

class Key : Entity {

private:
    int type; //chest, door, masterKey
    bool used; //idk yet but iterating over inventory may delete it if its used
public:
    Key(int type);
    int checkKey() const;


};

#endif //FERNQUEST_KEY_H

//
// Created by Codie Cottrell on 2/28/21.
//

#ifndef FERNQUEST_BRIDGE_H
#define FERNQUEST_BRIDGE_H

#include "Item.h"

class Bridge : Item {
private:
    static bool const placed{false};
public:
    Bridge();
    bool place();

};

#endif //FERNQUEST_BRIDGE_H

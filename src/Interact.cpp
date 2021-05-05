//
// Created by Codie Cottrell on 3/2/21.
//

#include <iostream>
#include "Interact.h"
using namespace std;

string Interact::playerMove() {
    return "moved player";
}

string Interact::playerItemInteract(std::string item) {
    if (item.compare("chest") == 0)
        return "opened chest";
    return "cannot interact";
}




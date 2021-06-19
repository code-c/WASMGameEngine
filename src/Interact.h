//
// Created by Codie Cottrell on 3/2/21.
//

#ifndef FERNQUEST_INTERACT_H
#define FERNQUEST_INTERACT_H

#include <iostream>
#include "Maps.h"
#include "json.hpp"

class Interact {
private:
    bool interacted;
    static Maps gameMaps;

public:
    Interact();
    static std::string playerMove();
    static std::string playerItemInteract(std::string item);
    static std::string getMap(int mapNum);
    static nlohmann::json getJSON(int mapNum);
};


#endif //FERNQUEST_INTERACT_H

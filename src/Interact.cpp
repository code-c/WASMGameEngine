//
// Created by Codie Cottrell on 3/2/21.
//

#include "Interact.h"
using namespace std;

Maps Interact::gameMaps = Maps();

Interact::Interact() {}

string Interact::playerMove() {
    return "moved player";
}

string Interact::playerItemInteract(std::string item) {
    if (item.compare("chest") == 0)
        return "opened chest";
    return "cannot interact";
}

string Interact::getMap(int mapNum) {
    string mapString = gameMaps.getMap(mapNum);
    return mapString;
}

 //not working because of UnboundTypeError
nlohmann::json Interact::getJSON(int mapNum) {
    nlohmann::json mapJSON = gameMaps.makeJSON(mapNum);
    return mapJSON;
}

int main() {
    cout << Interact::getMap(0);
    return 0;
}



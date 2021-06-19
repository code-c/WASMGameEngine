//
// Created by Codie Cottrell on 4/17/21.
//

#ifndef FERNQUEST_MAPS_H
#define FERNQUEST_MAPS_H

#include <map>
#include <string>
#include <vector>
#include "json.hpp"
#include "Maps.h"
#include <fstream>
#include <iostream>
#include <sstream>

struct Tile {
    bool interactive;
    int damage;
    std::string image;
    std::pair<int, int> position;
};

class Maps {
    std::vector<Tile> mainMap;
    std::vector<Tile> mainHouse;
    std::vector<Tile> generatedLayout;

    //std::map<int, std::string> cave;

public:
    Maps();

    void buildMaps();
    void buildMainMap();
    void buildMainHouse();
    void generateMap();
    nlohmann::json makeJSON(int mapNum);

    //getters
    std::string getMap(int mapNum);

    //print
    void printMap(int mapNum);

};

using nlohmann::json;

namespace std {
    inline void to_json(json& j, const Tile& t) {
        j = json{{"position", t.position}, {"image", t.image}, {"interactive", t.interactive}, {"damage", t.damage} };
    }

    inline void from_json(const json& j, Tile& t) {
        j.at("position").get_to(t.position);
        j.at("image").get_to(t.image);
        j.at("interactive").get_to(t.interactive);
        j.at("damage").get_to(t.damage);
    }
} // namespace ns


#endif //FERNQUEST_MAPS_H

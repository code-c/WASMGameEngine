//
// Created by Codie Cottrell on 4/17/21.
//

#ifndef FERNQUEST_MAP_H
#define FERNQUEST_MAP_H

#include <map>
#include <string>
#include <vector>

class Map {
    std::vector<std::map<int, std::string>> mapLayouts;
    std::map<int, std::map<int, std::string>> mainMap;
    std::map<int, std::string> mainHouse;
    //std::map<int, std::string> cave;

public:
    Map();
    Map(int mapNum);

    std::map<int, std::string> getMap(int mapNum);
    void buildMaps();
    void buildMap(int mapNum);
    void buildMainMap();
    void buildMainHouse();

};


#endif //FERNQUEST_MAP_H

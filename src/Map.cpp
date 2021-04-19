//
// Created by Codie Cottrell on 4/17/21.
//

#include "Map.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Map::Map() {
    //this->mapLayouts.push_back (this->mainMap);
    //this->mapLayouts.push_back (this->mainHouse);
    //this->buildMaps();
}

map<int, string> Map::getMap(int mapNum) {
    switch(mapNum){
        case 0:
            return mapLayouts.at(0);
        case 1:
            return mapLayouts.at(1);
        default:
            return mapLayouts.at(0);
    }

}

void Map::buildMaps() {
    for(int i; i < mapLayouts.size(); i++) {
        this->buildMap(i);
    }
}

void Map::buildMap(int mapNum) {
    switch(mapNum) {
        case 0:
            this->buildMainMap();
        case 1:
            this->buildMainHouse();
        default:
            this->buildMainMap();
    }
}

void Map::buildMainMap() {
    cout << "opening file" << endl;
    try {
        //declare variables
        string line, tileName;
        string tiles[] = {"grass", "gwbor", "water", "cliff", "wfalL", "wfalC", "wfalR", "pathe", "ocean", "swbor", "pwbor"};
        int rowIdx = 0;

        //open file
        ifstream mapFile ("/Users/codiecottrell/Documents/FernQuest/src/mainMap.txt", ios::in);

        //read through file line by line
        while(getline(mapFile, line)) {
            //add line to string stream to read
            stringstream stream(line);

            //  row     col     tilestring
            //map<int, map<int, string>> mainMap;

            // Keep track of the current column index
            int colIdx = 0;

            // Extract each tile assignment from line
            while(stream >> tileName){
                cout << "index: " << rowIdx << ", " << colIdx << endl;

                //store
                mainMap.insert(pair<int, pair<int, string&>> (rowIdx, pair<int, string>(colIdx, tileName));

                // Increment the column index
                colIdx++;
            }
            //increase the row index
            rowIdx++;
        }

            // Close file
            mapFile.close();

    } catch(exception& e){
        cout << "counldnt open file: " << e.what() << endl;
    }
}

void Map::buildMainHouse() {}

int main() {
    Map map;
    map.buildMainMap();
    return 0;

}
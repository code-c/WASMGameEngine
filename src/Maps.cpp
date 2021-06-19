//
// Created by Codie Cottrell on 4/17/21.
//

#include "Maps.h"

using namespace std;

// constructor that initializes and builds all maps
// eventually would like it to be multi threaded
Maps::Maps() {
    this->buildMaps();
}

// getMap: retrieves a map outputting the string version
string Maps::getMap(int mapNum) {
    nlohmann::json mapJSON = this->makeJSON(mapNum);
    string mapString = mapJSON.dump();
    return mapString;
}

// buildMaps builds all the maps in the layout map (this will be multi threaded in the future)
void Maps::buildMaps() {
    this->buildMainMap();
    this->generateMap(); // generates grassy feild
}

// this builds the Main map and stores it in a json format.
void Maps::buildMainMap() {
    try {
        //declare variables
        string line, tileName;
        string tiles[] = {"grass", "gwbor", "water", "cliff", "wfalL", "wfalC", "wfalR", "pathe", "ocean", "swbor", "pwbor"};
        int rowIdx = 0;

        //open file
        ifstream mapFile ("/Users/codiecottrell/Documents//myReactApp/src/external/mainMap.txt", ios::in);

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
                //cout << "index: " << rowIdx << ", " << colIdx << endl;

                //store
                Tile tile;
                tile.interactive = false;
                tile.damage = 0;
                tile.image = tileName;
                tile.position = make_pair(rowIdx, colIdx);

                this->mainMap.push_back(tile);

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

// create the main house object
void Maps::buildMainHouse() {}

void Maps::generateMap() {
    pair<int, int> mapDimentions = make_pair(20,20);

    for(int rowIdx = 0; rowIdx <= mapDimentions.first; rowIdx++){
        for(int colIdx = 0; colIdx <= mapDimentions.second; colIdx++){

            //store/generate data
            Tile tile;
            tile.interactive = false;
            tile.damage = 0;
            tile.image = "grass";
            tile.position = make_pair(rowIdx, colIdx);

            if(rowIdx == 0 || colIdx == 0 || colIdx == mapDimentions.second){
                tile.interactive = true;
                tile.image = "cliff";
            } else if (rowIdx == mapDimentions.first) {
                tile.interactive = true;
                tile.image = "ocean";
            } else if (rowIdx == mapDimentions.first - 1) {
                tile.interactive = true;
                tile.image = "ocean";
            } else if (rowIdx == mapDimentions.first - 2) {
                tile.image = "cliff";
            }

            this->generatedLayout.push_back(tile);
        }
    }
}

// this builds a JSON file using a library called nlohmann::json in JSON.hpp
nlohmann::json Maps::makeJSON(int mapNum){
    nlohmann::json json;
    switch(mapNum) {
        case 0:
            json = this->mainMap;
            return json;
        case 1:
            json = this->generatedLayout;
            return json;
        default:
            json = this->mainMap;
            return json;
    }
}

// printing functionality for testing no longer useful add in header file before implementing
//void Maps::printMap(int mapNum) {
//    (this changed) map = this->getMap(mapNum);
//    for(int i=0; i<map.size(); i++) {
//        Tile tile = map.at(i);
//        cout << tile.image << "\n";
//        cout << "position: " << tile.position.first << ", "<< tile.position.second << "\n";
//        cout << "interactive: " << tile.interactive << "\n";
//        cout << "damage: " << tile.damage << "\n\n";
//    }
//
//}

//int main() {
//    Maps maps;
//    string map = maps.getMap(0);
//    cout << map;
//    return 0;
//}
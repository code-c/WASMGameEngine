//
// Created by Codie Cottrell on 2/27/21.
//

#ifndef FERNQUEST_ENTITY_H
#define FERNQUEST_ENTITY_H

#include <vector>

class Entity {

private:
    int hp;
    bool interactive;
    std::vector<double> xCoordinate,yCoordinate;

public:
    void setHp(int hp);
    void setInteractive(bool interactive);

    int getHp() const;
    bool getInteractive() const;
    std::pair<std::vector<double>, std::vector<double>> getLocation();


    Entity(bool interactive, int hp, std::vector<double> xCoordinate, std::vector<double> yCoordinate);
    Entity(bool interactive, int hp);
    Entity(bool interactive);

    void updateLocation(std::vector<double> xCoordinate, std::vector<double> yCoordinate);

    //debug funcs
    void printLocation();


};


#endif //FERNQUEST_ENTITY_H

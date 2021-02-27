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
    bool interacted;
    std::vector<double> xCoordinate,yCoordinate;

public:
    void setHp(int hp);
    void setInteractive(bool interactive);

    int getHp() const;
    bool getInteractive() const;
    std::pair<std::vector<double>, std::vector<double>> getLocation();


    Entity(bool interactive, int hp, const std::vector<double>& xCoordinate, const std::vector<double>& yCoordinate);
    Entity(bool interactive, int hp);
    Entity(bool interactive);
    Entity();

    void updateLocation(const std::vector<double>& xCoordinate, const std::vector<double>& yCoordinate);
    void interact();

    //debug funcs
    void printLocation();


};


#endif //FERNQUEST_ENTITY_H

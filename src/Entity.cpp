//
// Created by Codie Cottrell on 2/27/21.
//

#include <iostream>
#include <utility>
#include "Entity.h"
using namespace std;

// constructors

//default constructor
Entity::Entity() : interactive(false), hp(0) , xCoordinate({0,0}), yCoordinate({0,0}){}

Entity::Entity(bool interactive, int hp, const vector<double>& xCoordinate, const vector<double>& yCoordinate) : interactive(interactive), hp(hp) , xCoordinate(std::move(xCoordinate)), yCoordinate(std::move(yCoordinate)){}

Entity::Entity(bool interactive, int hp) : interactive(interactive), hp(hp), xCoordinate({0,0}), yCoordinate({0,0}){}

Entity::Entity(bool interactive) : interactive(interactive), hp(0) , xCoordinate({0,0}), yCoordinate({0,0}) {}

// variable setters and getters

//set the health points of an entity
void Entity::setHp(int hp) {
    Entity::hp = hp;
}

//set the interactiveness of an entity
void Entity::setInteractive(bool interactive) {
    Entity::interactive = interactive;
}

//get the interactivity of an entity
bool Entity::getInteractive() const {
    return Entity::interactive;
}

//getter for the health points of an entity
int Entity::getHp() const {
    return hp;
}

//get the location of an entity
pair<vector<double>, vector<double>> Entity::getLocation() {
    vector<double> x = Entity::xCoordinate;
    vector<double> y = Entity::yCoordinate;
    pair<vector<double>, vector<double>> location;
    location = make_pair(x,y);
    return location;

}

// update the location of an entity
void Entity::updateLocation(const vector<double>& xCoordinate, const vector<double>& yCoordinate){
    if (Entity::xCoordinate != xCoordinate) {
        Entity::xCoordinate = xCoordinate;
    }
    if (Entity::yCoordinate != yCoordinate) {
        Entity::yCoordinate = yCoordinate;
    }
}

//test function to print the coordinates of an entity
void Entity::printLocation() {
    //accessing the coordinates as start = (x,y) end = (x,y)
    double xStart = Entity::xCoordinate.at(0);
    double yStart = Entity::yCoordinate.at(0);
    double xEnd = Entity::xCoordinate.at(1);
    double yEnd =Entity::yCoordinate.at(1);

    cout<< "start corner: " << "( " << to_string(xStart) << ", " << to_string(yStart) << " )" << endl;
    cout<< "end corner: " << "( " << to_string(xEnd) << ", " << to_string(yEnd) << " )" << endl;
}

//testing
//int main(){
//    vector<double> xCoordinates {0,10};
//    vector<double> yCoordinates {0,10};
//    Entity entity(true, 100, xCoordinates, yCoordinates);
//    int hp = entity.getHp();
//    entity.printLocation();
//    exit(0);
//}

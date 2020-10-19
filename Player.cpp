#include <iostream>
#include <stdlib.h>
#include <vector>
#include <zconf.h>
#include "Item.h"
#include "Player.h"
using namespace std;


Player::Player() : packSize(10), itemHeld(0) { }

void Player::walk() {
    for(int i = 0; i <= 5; i++){
        cout << "..." << endl;
        sleep(1);
    }
}

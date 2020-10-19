/* --------------------
 * --- Player Class ---
 * --------------------
 *  AUTHOR: Codie Cottrell
 * Here is where the game starts. A player creates their name on screen and the player is initialized!
 * A Game Object is made and that's the magic. We interact with the game here. Only things that are
 * needed in the game storyline are stored in this player class.
*/

#include <iostream>
#include <vector>
#include <zconf.h>
#include "Item.h"
#include "Player.h"
#include "Game.h"

using namespace std;

// constructor for player
Player::Player() : packSize(10), itemHeld() { }
// overloaded constructor
Player::Player(string name) {

}

void Player::walk() {
    for(int i = 0; i <= 5; i++){
        cout << "..." << endl;
        sleep(1);
    }
}

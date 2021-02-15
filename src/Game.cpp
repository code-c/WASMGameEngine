/* ------------------------------------
 * ------------ Game Class ------------
 * ------------------------------------
 *
 * This is where the magic happens. Everything in here is how the player
 * interacts with the storyline and quests, as well as gets around the
 * world!
 */
#include <iostream>
#include "Game.h"
using namespace std;

Game::Game() {
    cout << "the game has been generated" << endl;
}

void Game::loadStory() {
    cout << "The story has loaded: \n \n \n You walk through the path and come across ---" << endl;
}


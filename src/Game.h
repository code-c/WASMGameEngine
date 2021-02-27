/* -------------------------------------------
 * ------------ Game Class Header ------------
 * -------------------------------------------
 *
 * This is where the magic happens. Everything in here is how the player
 * interacts with the storyline and quests, as well as gets around the
 * world!
 */

#ifndef GAME_H
#define GAME_H

class Game {
    std::string currentMap;
public:
    Game();
    void loadStory();

};

#endif

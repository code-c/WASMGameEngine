/* ---------------------------
 * --- Player Class Header ---
 * ---------------------------
 *  AUTHOR: Codie Cottrell
 * Here is where the game starts. A player creates their name on screen and the player is initialized!
 * A Game Object is made and that's the magic. We interact with the game here. Only things that are
 * needed in the game storyline are stored in this player class.
*/

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    std::string name; // the name they choose
    int health;
    int hunger;
    int environmentalistGrade;
    int packSize;
    Item itemHeld; // reference to item in pack (anything magical, staff, shield, etc)
    Game game;
    std::vector<Item> pack;
    Player();
    Player(std::string name);
    void walk();
};

// strenght perameter
// witty perameter
// stealth perameter
//

// clothes perameter?

// item interaction
// holding
//
// money

// find magician to grant stuff and improve upon equipment to him (he is many places)

// connect things from a stream (beaver builds you a bridge)
// many interactions with water
// moat (has to unlock draw bridge in some away)
  // always something in castle for power source(maybe a really good sourcxe)


// he can get stuff from animals


// Items
// pinecones
// acorns
// fruits
//

//characters
// all animals in the forest
  // each animal teaches the main character something
    // if he saves them though

// raccoons are theives stay away from them
#endif

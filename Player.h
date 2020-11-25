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

// I am still unsure why I need to include these headers here
#include "Game.h"
#include "Item.h"
#include <boost/serialization/string.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class Player {
private:
    // boost serialization save and load of the player
    friend class boost::serialization::access;
    template<class Archive>
    void save(Archive &ar, const unsigned int version) const {
        ar & BOOST_SERIALIZATION_NVP(name);
        std::cout << "Saved Game!!" << std::endl;
    };
    template<class Archive>
    void load(Archive &ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(name);
        std::cout << "Loaded Game!!" << std::endl;
    };
    BOOST_SERIALIZATION_SPLIT_MEMBER()
    //template<class Archive>
//void Player::serialize(Archive &archive, const unsigned int version) {
//    boost::serialization::split_member(archive, *this, version);
//}
public:
    std::string name; // the name they choose
    Game game;
    int health{100};
    int hunger{10};
    int environmentalistGrade{0};
    int packSize{20};
    Item itemHeld; // reference to item in pack (anything magical, staff, shield, etc)
    std::vector<Item> pack;
    Player();
    Player(std::string name);
    void openGame();
    void walk();
};
// boost serialization of the player


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

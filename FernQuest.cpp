//the main for the everything where we run the game.
// author: Codie Cottrell
#include <fstream>
#include <iostream>
#include <vector>
#include "Player.h"
using namespace std;

Player createNewPlayer() {
    string name;
    cout << "enter your name" << endl;
    cin >> name;
    Player newPlayer = Player(name);

    // open a new profile file to store the player  it
    try{
        ofstream playerProfile (name + ".txt");
        boost::archive::
        (playerProfile, newPlayer);

    } catch (exception const& e) {
        cout << "could not create player profile error: " << e.what() << endl;
    }

    return newPlayer;
}

Player menuLoop() {
    do {
        int option = 0; // quick note we have a loop on default.
        cout << "Welcome to Fern Quest! please enter a number from the following options:" << endl;
        cout << "\n 1 - New Game \n 2 - Resume Game \n 3 - Settings \n 4 - Exit" << endl;
        cin >> option;
        // start or create a game
        switch(option) {
            case 1: {
                Player newPlayer = createNewPlayer();
                return newPlayer;
            }
            case 2: {
                cout << "select your profile" << endl;
                // create a way to store the player.
                // return player from selected num
                break;
            }
            case 3: {
                cout << "there are no settings right now" << endl;
                break;
            }
            case 4: {
                cout << "bye!" << endl;
                exit(0);
            }
            default: {
                cout << "try again! please select 1, 2 or 3" << endl;
                break;
            }
        }
    } while(true);
}

int main(){
        Player player = menuLoop();
        player.walk();
        //string eddie = "eddie";
        //Player playerOne = Player(eddie);
        //playerOne.walk();
}


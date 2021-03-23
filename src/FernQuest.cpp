//the main for the everything where we run the game.
// author: Codie Cottrell
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include "Player.h"
#include <boost/algorithm/string.hpp>
using namespace std;

// use of the C++17 standard library filesystem!
struct path_leaf_string
{
    std::string operator()(const std::__fs::filesystem::directory_entry& entry) const
    {
        return entry.path().filename().generic_string(); // return string of the file
    }
};

// function that reads a directory and stores the files as strings in a vector.
void readDirectory(const std::string& name, vector<string>& v)
{
    std::__fs::filesystem::path p(name);
    std::__fs::filesystem::directory_iterator start(p);
    std::__fs::filesystem::directory_iterator end;
    std::transform(start, end, std::back_inserter(v), path_leaf_string());
}

// This is in case we need to delete a file
// note: this will throw errors if not done right and is not working great.
int deleteProfile(vector<string> playerProfiles) {
    //declaring variables
    bool valid = false;
    int num = 0;
    int selectedSaveFile; // saveFile number
    string player, saveFile;

    // we need to verify the input of the user we stick it in a do while loop
    do {
        num = 0;
        int selected = 0; // selection
        // take playerProfile names and output them (also takes the .xml off the end of the strings
        for(const string& profileName: playerProfiles){
            size_t lastIndex = profileName.find_last_of(".");
            ++num; // start from 1
            cout << num << ". " << profileName.substr(0, lastIndex) << endl; // new line char for easy viewing
        }
        // prompting user
        cout << "please enter the number of the profile you wish to delete.\n"
                "or 0 for quit" << endl;
        // get input of the saveFile num and test for valid input
        if(cin >> selected) {
            if (selected == 0){
                return 0;
            }
            selectedSaveFile = selected;
            valid = true;
        } else{
            // if input wasn't valid clear cin
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // clears whole line of characters
        }
    } while(!valid);


    //retrieving the players profile name from list
    player = playerProfiles.at(--selectedSaveFile); // undo the +1 done above
    // converting string to const char *
    saveFile = "/Users/codiecottrell/Documents/FernQuest/playerProfiles/" + player;
    const char * c = saveFile.c_str();

    // removing file
    try {
        if(remove(c) == 0){
        cout << "the saveFile: " + player + " has been deleted" << endl;
        return 1;
        }
    } catch(exception const& e){
        cout << "the saveFile could not be deleted. error: " << e.what() << "\n" << endl;
        return 0;
    }
}

// loads the playerProfile names and loads a player Profile from selection
// sets the current player and returns the value of player.
Player loadPlayers() {
    // declare variables
    bool valid; // valid input
    int num = 0; // number in cout next to name
    int selectedProfile; // number of selected profile
    string player;
    vector<string> playerProfiles; // vector of profile names

    Player currentPlayer;

    // read the files as strings from the profile directory into the vector
    readDirectory("/Users/codiecottrell/Documents/FernQuest/playerProfiles/", playerProfiles);

    do {
        num = 0;
        int selected = 0; // selection
        // take playerProfile names and output them (also takes the .xml off the end of the strings
        for(const string& profileName: playerProfiles){
            size_t lastIndex = profileName.find_last_of(".");
            ++num; // start from 1
            cout << num << ". " << profileName.substr(0, lastIndex) << endl; // new line char for easy viewing
        }
        // prompting user
        // also I would like to point out the use of a number compared to writing a name.
        // I am also aware of the exploits possible here but its just for debug purposes really.
        cout << "please enter the number of the profile you wish to load \n"
                "or 0 for quit" << endl;
        // get input of the saveFile num and test for valid input
        if(cin >> selected) {
            if (selected == 0){
                exit(0);
            }
            selectedProfile = selected;
            valid = true;
        } else{
            // if input wasn't valid clear cin
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); // clears whole line of characters
        }
    } while(!valid);

    // open the txt file associated with profile name
    player = playerProfiles.at(--selectedProfile); // undo the +1 done above
    ifstream currentProfile("/Users/codiecottrell/Documents/FernQuest/playerProfiles/" + player);
    boost::archive::text_iarchive ar(currentProfile);

    // store the playerProfile into the empty playerObject.
    ar & BOOST_SERIALIZATION_NVP(currentPlayer);
    return currentPlayer;

}

// loads a new player Profile from given name only if empty spot available.
// sets it to the current player and returns the value of player.
// can delete players from this option as well.
Player createNewPlayer() {
    // declare variables
    string name; // new name
    vector<string> playerProfiles; // vector of profile names

    // read in the current profiles to vector so that we dont overwrite
    readDirectory("/Users/codiecottrell/Documents/FernQuest/playerProfiles/", playerProfiles);

    // check to see if the number of profiles exceeds 3 and run delete command
    if(playerProfiles.size() >= 5){
        // some inner loop variables
        bool moveOn = false;
        string answer;
        cout << "sorry there are no more empty profiles.\n "
                "Would you like to delete one?\n"
                "(y)es or (n)o?\n"
                "(q)uit!\n" << endl;

        while(!moveOn) {
            cin >> answer;
            boost::algorithm::to_lower(answer);

            if (answer.compare("y") == 0 || answer.compare("yes") == 0) {
                if (deleteProfile(playerProfiles) == 0){
                    exit(0);
                } else {
                    moveOn = true;
                }
            } else if (answer.compare("n") == 0 || answer.compare("no") == 0) {
                return loadPlayers();
            }else if (answer.compare("q") == 0 || answer.compare("quit") == 0) {
                exit(0);
            } else{
                cout << "please enter 'y' or 'n' or q to exit" << endl;
            }
        }
    }

    // get name as input from user
    cout << "enter your new players name" << endl;
    cin >> name;

    //check the name against current profiles and ask  name if needed
    //                                                          adding the txt file ending
    while(find(playerProfiles.begin(), playerProfiles.end(), (name+".txt")) != playerProfiles.end()){
        cout << "sorry that player exists already. Enter a new name for your player: \n" << endl;
        cin >> name;
    }

    // create the new player
    Player newPlayer = Player(name);

    // open a new profile text file to store the player
    try{
        // note: if no playerProfiles folder exists this will fail.
        // create new save file
        ofstream playerProfile("/Users/codiecottrell/Documents/FernQuest/playerProfiles/" + name + ".txt"); //create file for player
        boost::archive::text_oarchive saveFile(playerProfile);
        saveFile << BOOST_SERIALIZATION_NVP(newPlayer);
        playerProfile.close();
        return newPlayer;
    } catch (exception const& e) {
        cout << "could not create player profile error: " << e.what() << endl;
    }
}

// this is the main menu loop that exits once a player profile is selected
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
                cout << "Enter your profiles number or name" << endl;
                Player currentPlayer = loadPlayers();
                return currentPlayer;
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

//int main(){
//        Player player = menuLoop();
//        player.openGame();
//}


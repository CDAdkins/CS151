//#pragma once
#include <string>
#include <vector>
//#include "property.h"
//#include "card.h"
using namespace std;

class Player {
    private:
    string name; // The name of the player.
    //char piece; // Symbol to identify the player on the board.
    int money; // The aount of money the player currently has.
    //vector<Property> properties; // Vector of properties owned by the player.
    //vector<Card> cards; // Vector of cards currenty held by the player.
    int position; // Player's position on the board.
    bool inJail; // Whether or not the player is in jail.
    int jailTimeLeft; // How many more turns the player must stay in jail for.
    bool doubles; // Was the players last roll doubles.

    public:
    // Constructor
    Player(string aName); // Only constructor necessary for this class.

    // Getters and Setters
    int getRoll(); // Function to simulate a roll and keep track of doubles.
    void setDoubles(bool result); // To be called within getRoll() if there are doubles.
    string getName(); // Returns this player's name.
    int getMoney(); // Returns this player's money.
    int getPosition(); // Returns this player's position.
    bool isInJail(); // Returns true if the player is in jail, false if they are not.
    int getJailTimeLeft(); // Returns amount of turns the player must spend in jail.
    
    // Member Functions
    bool pay(int num, Player otherPlayer); // Function to transfer money from this player to another.
    void goToJail(); // Sends the player to jail.
    void doTime(); // Decrements jailTimeLeft. If jailTimeLeft is <= 0, set inJail to false.
    void movePosition(int num); // Moves the player forward a number of spaces.
    void setPosition(int num); // Moves the player to a specific position.

};
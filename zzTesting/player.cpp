#include <random>
#include <string>
#include "player.h"
using namespace std;

// Constructor
Player::Player(string aName) {
    name = aName;
    //piece = aPiece;
    money = 1500;
    position = 0;
    inJail = false;
    jailTimeLeft = 0;
    doubles = false;
}

// Getters and Setters
void Player::setDoubles(bool result) {
    doubles = result;
    inJail = false; // If the player is in jail, let them out.
}
string Player::getName() { return name;}
int Player::getMoney() {return money;}
int Player::getPosition() {return position;}
bool Player::isInJail() {return inJail;}
int Player::getJailTimeLeft() {return jailTimeLeft;};

// Member Functions
int Player::getRoll() {
    // Initializing the dice
    int d1 = 0;
    int d2 = 0;
    int roll;
    bool areDoubles = false; // Whether or not the two dice are the same value.
    
    random_device rd; // Initializing our seed.
    mt19937 rng(rd()); // Mersenne-Twister engine to generate numbers.
    uniform_int_distribution<int> uni(1, 6);
    //auto random_integer = uni(rng);
    d1 = uni(rng);
    d2 = uni(rng);
    d1 == d2 ? areDoubles = true : doubles = false;
    setDoubles(areDoubles); // Tell the player that they rolled doubles.
    roll = d1+d2; // Set the value of the roll.
    return roll; // Return the sum of both dice to the user.
}
bool Player::pay(int num, Player otherPlayer) {
    if (money < num) { // If the player does not have enough money.
        return false;
    }
    // If the player has enough money
    money -= num; // Take the money from this player.
    otherPlayer.money += num; // Add the money to the other player.
    return true; // Confirm the transaction has completed.
}
void Player::goToJail() {
    inJail = true;
    setPosition(10);
}
void Player::doTime() {jailTimeLeft--;}
void Player::movePosition(int num) {position += num;}
void Player::setPosition(int num) {position = num;}

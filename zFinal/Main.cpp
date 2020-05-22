/*  Main.cpp
    Author: Chris Adkins
    Module: 17
    Project: Final
    Problem Statement: This is a shortened Monopoly game you can play on the command line.

    Algorithm:
        1. Create the Player class
			a. Give the player private variables for name, money, assets, whether they're in jail.
			b. Create a constructor that initializes these values.
			c. Create a destructor that deletes all of the references to the player's assets.
			d. Create a print funtion that just prints the players name, money and assets.
			e. Overload the << operator to easily print the players information.
			f. Create getters to retrieve aspects of the player (name, money, properties).
			g. Create setters mostly for sending the player to jail.
			h. Create a function to pay rent when stepping on another player's asset.
			i. Create addAsset which takes an asset from the board and changes its owner to the calling player.
			j. Make a funciton that lets the player simulate two dice rolls.
		2. Create an abstract base class called Slot.
			a. Each slot has a name and a size.
			b. Create a constructor, destructor, a getter for the name and a play function.
		3. Create a subclass of Slot called Go,
			a. Go just has an overloaded play function.
		4. Create anoter subclass of Slot called Asset.
			a. Assets have ints for rent cost and owner.
			b. Create the constructors and destructors as well as getters and setters.
			c. Overload the play function for the asset class as well.
		5. Create another subclass of Slot called Chance.
			a. Chance's have an int caled amount which determines how much the player gets when they land on it.
		6. Create one last subclass of Slot called jail.
			a. Jail needs an overloaded play() function for when the player lands on it.
		7. Create the Board class.
			a. Create an enumeration with four possible actions, END_GAME, PLAY, PRINT_BOARD, PRINT_ASSETS.
			b. The Board has an int for size as well as width, an array of Slots and a string to represent the drawing of the board.
			c. Create protected functions to increase the size of the board, draw the board, and print help to the user.
			d. Create public functions to add all of the different kinds of slots to the board.
			e. Create getters for accessing the slots in the board
    Classes Needed:
		"Board.h"  - For accessing the Board class.
		"Slot.h"   - For access to the Slot class and its subclasses.
        <iostream> - For printing to the user.
*/

#include "Board.h"
#include "Slot.h"
#include <iostream>
using namespace std;

int main() {
	Board monopoly;
	cout << monopoly;
	Player players[2] = { Player("Chris", monopoly, 300), Player("Sam", monopoly, 300) };
	monopoly.play(players);
}
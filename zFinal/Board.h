/*  Board.h
    Author: Chris Adkins
    Module: 17
    Project: Final
    File Description: This is the header file for our Board class.
*/

#pragma once

#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

// Forward Declaration
class Slot;
class Player;

class Board {
public:
	// Possible actions the player can take each turn.
	enum action {END_GAME, PLAY, PRINT_BOARD, PRINT_ASSETS};

protected:
	int size; // The number of spaces on the board
	Slot **m_arr; // The array of spaces our board has.
	//string m_board_image[6][5];
	string m_board_image[6][5];
	int m_slot_width; // The width of a slot on the board.
	void increaseBoard(); // Increase the size of the board by one.
	void initBoardImage(); // Draw the board
	void printHelp(); // Print the help menu to the user.
	Board::action getCommand() const; // Get the command from the user.

public:
	// Constructor
	Board();
	// Destructor
	~Board();
	// Overloading the [] operator
	Slot* operator[](int idx) const;
	// Function to advance the game each turn.
	void play(Player* players);
	// Add an asset slot to the board.
	void addAssetSlot(const string& propertyName);
	// Add a Go slot to the board.
	void addGoSlot(const string& text);
	// Add a jail slot to the board.
	void addJailSlot(const string& text);
	// Add a chance slot to the board.
	void addChanceSlot(const string& text, int amount);
	// Overloading the << operator for printing.
	friend ostream& operator<<(ostream& os, const Board& b);
	// Getting the object in a slot by index.
	Slot* getSlot(int inx) const;
	// Getter for the size of the board.
	int getSize();
};
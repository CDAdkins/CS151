#pragma once
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

const int GO_MONEY = 50;

class Slot;
class Board;
class Asset;

class Player {
protected:
	int number; // Dictates the order of turns.
	string name; // The players name.
	int money; // How much money this player has.
	bool inJail; // Whether or not this player is in jail.
	int position; // The index of the slot on board.							
	Asset* assets; // Assets that this player owns.
	int numAssets; // Number of assets that this player owns.
	Board* board; // Pointer to our board.

public:
	static int numPlayers; // Keeps track of how many players the game already has.

	// Constructor
	Player(string name, Board& BB, int balance);

	//	Destructor 
	~Player();

	bool payRent(int amount);
	bool addAsset(Asset* a);
	bool drawDice();

	// Asset stack
	void pop();
	void push(Asset* asset);

	// Getters
	int getNumAssets()const;
	int getPlayerNumber()const;
	int getMoney()const;
	static int getNumPlayers();

	string getName()const;

	// Setters
	void setInJail();
	void addMoney(int balance);

	void print() const;
	friend ostream& operator<<(ostream& os, const Player& P);
};

int randNum(int low, int high);

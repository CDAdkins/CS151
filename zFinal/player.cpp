#include "Player.h"
#include "Board.h"
#include "Slot.h"
#include <random>
using namespace std;

// Static players counter init.
int Player::numPlayers = 0;

// Constructor 
Player::Player(string aName, Board& BB, int balance) : number(++numPlayers), name(aName) {
	board = &BB;
	money = balance;
	inJail = false;
	position = 0;
	assets = nullptr;
	numAssets = 0;
}

// Destructor 
Player::~Player(){delete[] assets;}

// Printing the status of the player (balance and assent list) at the end od his turn.
void Player::print() const {
	cout << endl << name << " Balance: " << money << endl << "Assets: ";
	if (!numAssets)
		cout << " none";
	else {
		for (int i = 0; i < numAssets; i++) {
			//cout << assets[i].get_asset_name() << " | ";
			cout << assets[i].getName() << " | ";
		}
	}
	cout << endl;
}


ostream& operator<<(ostream& os, const Player& P) {
	P.print();
	return os;
}

// Getters
int Player::getPlayerNumber() const {return number;}
int Player::getNumPlayers() {return numPlayers;}
string Player::getName()const {return name;}
int Player::getNumAssets() const {return numAssets;}
int Player::getMoney()const {return money;}

//Setters
// Updating the Jail flag of the specific player.
void Player::setInJail() {inJail = true;}
// Adding the amount to the player's balance.
void Player::addMoney(int balance) {money += balance;}

// When steping on another's player Asset, reducing the specific rent from balance of the player.
bool Player::payRent(int amount) {
	cout << "This is a private Asset! You have to pay: " << amount << " $" << endl;
	while (amount > money) {
		cout << "You don't have enough money! " << endl;
		if (numAssets == 0) {
			cout << "You dont have any assets, GAME OVER!" << endl;
			return false;
			exit(EXIT_SUCCESS);
		}
		else {
			cout << assets[0].getName() << " has been sold for " << assets[0].getCost() << " $" << endl;
			assets[0].setOwner(-1); // Setting the asset to no longer have an owner once sold.
			pop();
		}
	}
	addMoney(-amount);
	
	return true;
}

// Adding an Asset to the players Asset's stack
bool Player::addAsset(Asset* a) {
	if (a->getCost() > money) {
		cout << "Not enough money!" << endl;
		return false;
	}
	else {
		a->setOwner(number);
		push(a);
		cout << "Purchase confirmed!" << endl;
		return true;
	}
}

// Poping the first Asset that purchased as requested.
void Player::pop() {
	money += assets[0].getCost();
	assets[0].setOwner(-1);
	Asset *temp = new Asset[numAssets - 1];

	for (int i = 0; i < numAssets - 1; i++)
		temp[i] = assets[i + 1];

	delete[] assets;
	assets = temp;
	numAssets--;
}

// Adding an Asset to the players assets.
void Player::push(Asset* asset) {
	money -= asset->getCost();
	Asset *temp = new Asset[numAssets + 1];
	for (int i = 0; i < numAssets; i++)
		temp[i] = assets[i];

	temp[numAssets] = *asset;

	delete[] assets;
	assets = temp;
	numAssets++;
}

bool Player::drawDice() {
	// Checking to see if the player is in jail.
	if (inJail) {
		cout << "You are in Jail!" << endl;
		inJail = false; // Set inJail to false so the player can move next turn.
		return true;
	}
	// If the player is not in jail, roll the dice.
	int dice = randNum(1, 6); // Generate a random number between 1 and 6.
	

	 if ((position + dice) >= 18) { // If the player's position plus their roll places them at or after go.
		 cout << "Passed GO!" << endl;
		 addMoney(GO_MONEY);
		 cout << "\nYou move " << dice << " steps and land on " << board->get_slot((position + dice) % 18)->getName() << endl;
	 } else {
		 cout << "\nYou move " << dice << " steps and land on " << board->get_slot((position + dice))->getName() << endl;
	 }

	position = ((position + dice) % 18);
	
	return board->get_slot(position)->play(this);
}

// Generate random number between min and max (inclusive).
int randNum(int min, int max) {
	srand(time(NULL));
	rand();
	rand();
	int num;
	num = min + (rand() % static_cast<int>(max - min + 1));
	return num;
}
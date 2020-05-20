#pragma once
#include "Player.h"
using namespace std;

const int MIN_RENT = 20;
const int MAX_RENT = 100;
const int MIN_COST = 50;
const int MAX_COST = 125;

// Slot Base Class
class Player;
class Slot {

protected:
	int size;
	string name;

public:
	// Constructor
	Slot(int slotNum, string aName);
	Slot(int slotNum);

	//	Destructor 
	virtual ~Slot() = 0;

	virtual bool play(Player* p) = 0;
	//static int slotCounter;

	// Virtual Getter
	virtual string getName() const = 0;
};

// Go
class Go : public Slot {
protected:
	string order;

public:
	// Constructor
	Go(int size, string order);
	//	Destructor 
	~Go();

	// Getters 
	string getName() const;


	bool play(Player* p);
};

// Asset
class Asset : public Slot {
protected:
	int rent;
	int cost;
	int owner;

public:
	// Constructor
	Asset(int size = 0, string aName = "");
	//	Destructor 
	~Asset();
	//Copy Constructor
	Asset(const Asset& AA);

	// Getters
	string getName() const;
	int getOwner() const;
	int getCost() const;
	int getRent() const;

	// Setters
	void setOwner(int player_num);
	bool play(Player* p);
};

// Chance
class Chance : public Slot {
protected:
	string order;
	int amount;

public:
	// Constructor
	Chance(int size, string order, int amount);
	//	Destructor 
	~Chance();
	// Getter
	string getName() const;
	bool play(Player* p);
};

// Jail
class Jail : public Slot {
protected:
	string order;

public:
	// Constructor
	Jail(int size, string order);
	//	Destructor 
	~Jail();

	// Getter
	string getName() const;

	bool play(Player* p);
};
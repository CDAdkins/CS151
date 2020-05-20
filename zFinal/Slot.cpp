#include "Slot.h"
using namespace std;

// Slot
// Constructor.
Slot::Slot(int slotNum, string aName){size = slotNum; name = aName;}
Slot::Slot(int slotNum){size = slotNum;}
// Destructor.
Slot::~Slot(){}

// Go
// Constructor.
Go::Go(int size, string order) : Slot(size)
{
	name = "Go!";
	order = "god speed!";
}
// Destructor.
Go::~Go(){}

string Go::getName() const {return name;}

bool Go::play(Player* p) {
	cout << order << endl;
	return true;
}

// Asset
// Constructor
Asset::Asset(int size, string aName) : Slot(size, aName) {
	owner = -1;
	rent = randNum(MIN_RENT, MAX_RENT);
	cost = randNum(MIN_COST, MAX_COST);
}
// Destructor.
Asset::~Asset(){}

// Copy Constructor
Asset::Asset(const Asset& AA) : Slot(AA.size, AA.name) {
	rent = AA.rent;
	cost = AA.cost;
	owner = AA.owner;
}

string Asset::getName() const {return name;}
int Asset::getOwner() const {return owner;}
int Asset::getCost() const {return cost;}
int Asset::getRent() const {return rent;}
void Asset::setOwner(int player_num) {owner = player_num;}

// Confirm purchase, updating balance and asset list.
bool Asset::play(Player* p) {
	if (getOwner() == -1) { // If the asset doesn't have an owner.
		cout << "Do you want to buy " << name << " for $" << cost << " ? (1) To buy, (any key) Continue without buying: " ;
		int choice;
		cin >> choice;
		if (choice == 1) {
			p->addAsset(this);
		}
		return true;
	}
	else if (getOwner() != p->getPlayerNumber()) { // If the asset does have an owner.
		if (!p->payRent(rent))
			return false;
	}
	else // If you land on your own asset.
		cout << getName() << " is Your asset" << endl;
	return true;
}

// Chance
// Constructor.
Chance::Chance(int size, string anOrder, int amount) : Slot(size) {
	name = "Chance!";
	order = anOrder;
	amount = amount;
}
// Destructor.
Chance::~Chance(){}

string Chance::getName() const {return name;}

// Printing orders of the slot and updating the balance
bool Chance::play(Player* p) {
	cout << order << 25 << "\n";
	p->addMoney(25);

	return true;
}

// Jail
// Constructor.
Jail::Jail(int size, string order) : Slot(size) {
	name = "Jail!";
	order = "You are in Jail! wait 1 turn";
}
// Destructor.
Jail::~Jail() {}

string Jail::getName() const {	return name;}

// printing orders of the slot only and setting flags as requested
bool Jail::play(Player* p) {
	cout << order << endl;
	p->setInJail();

	return true;
}
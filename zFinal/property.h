#pragma once
#include <string>
#include "space.h"
#include "player.h"
using namespace std;

class Property : public Space {
    private:
    string color; // The color of the property. Utility if utility / railroad.
    int value; // How much the property costs to buy.
    Player owner; // Player that owns the property.
    int houses; // Number of houses the owner has built on the property.

    public:
    // Constructor
    Property(string aColor, string aName, int aValue);

    // Getters and Setters
    string getColor(); // Returns the color of this property.
    string getName(); // Returns the name of this property.
    int getValue(); // Returns the value of this property.
    Player getOwner(); // Returns the owner of the property.
    Player setOwner(Player aPlayer); // Sets the owner to a player.
    void addHouse(); // Adds a house to this property. 
};
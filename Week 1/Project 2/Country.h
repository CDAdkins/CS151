/*  Country.h
    Author: Chris Adkins
    Module: 1
    Project: 2
    File Description: 
    This is the header for our Country class, it has our prototypes and properties that define what a country is here.
*/

#pragma once
#include <string>

using namespace std;

class Country {
private:
    string name; // The name of our country.
    int population; // How many people live in this country.
    int area; // The area in sq miles

public: // Constructor && Getters
    Country(string name, int population, int area);
    string getName();
    int getPopulation();
    int getArea();
};
/*  Country.cpp
    Author: Chris Adkins
    Module: 1
    Project: 2
    File Description: 
    This file contains the function definitions for our country class.
*/

#include "Country.h"
#include <string>

using namespace std;

Country::Country(string name, int population, int area) { // Defining a basic constructor.
    this->name = name;
    this->population = population;
    this->area=area;
}

// Getters.
string Country::getName() {
    return name;
}

int Country::getPopulation() {
    return population;
}

int Country::getArea() {
    return area;
}
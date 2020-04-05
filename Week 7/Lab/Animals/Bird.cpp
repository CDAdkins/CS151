/*  Bird.cpp
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    File Description: This is a subclass of the Animal class.
    
*/

#include "Bird.h"
#include <iostream>

using namespace std;

Bird::Bird(string aName) : Animal(aName) {
    cout << "The Bird " << Animal::getName() << " has been created..." << endl;
}

void Bird::makeNoise() {
    cout << "The Bird " << Animal::getName() << " is chirping." << endl;
}

void Bird::showInfo() {
    cout << "The Bird " << Animal::getName() << "." << endl;
}
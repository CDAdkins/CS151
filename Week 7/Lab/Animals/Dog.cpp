/*  Dog.cpp
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    File Description: This is a derivitive class of the Animal class.
    
*/

#include "Dog.h"
#include <iostream>

using namespace std;

Dog::Dog(string aName, string aBreed) : Animal(aName), breed(aBreed) {
    cout << "The Dog " << Animal::getName() << " of breed " << breed << " has been created..." << endl;
}

void Dog::makeNoise() {
    cout << "The Dog " << Animal::getName() << " is barking." << endl;
}

void Dog::showInfo() {
    cout << "The Dog " << Animal::getName() << " of breed " << breed << "." << endl;
}
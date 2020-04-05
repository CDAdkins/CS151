/*  Animal.cpp
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    File Description: This is the base class that the Dog and Bird class are derived from.
    
*/

#include "Animal.h"
#include <iostream>

using namespace std;

Animal::Animal(string aName) : name(aName) {
    cout << "The Animal " << name << " has been created..." << endl;
}

void Animal::sleep() {
    cout <<"The Animal " << name << " is asleep." << endl;
}

void Animal::makeNoise() {
    cout <<"The Animal " << name << " is making a noise." << endl;
}

void Animal::showInfo() {
    cout << "The Animal " << name << "." << endl;
}

string Animal::getName() {
    return name;
}

void Animal::setName(string name) {
    this->name = name;
}
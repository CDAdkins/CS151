/*  Animal.h
    Author: Chris Adkins
    Module: 7
    Project: Lab 2
    File Description: This is the header file from our Animal class.
    
*/

#pragma once
#include <iostream>

using namespace std;

class Animal {
private:
    string name;

public:
    Animal(string);
    void sleep();
    void makeNoise();
    void showInfo();
    string getName();
    void setName(string);
};
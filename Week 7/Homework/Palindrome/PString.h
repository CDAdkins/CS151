/*  PString.h
    Author: Chris Adkins
    Module: 7
    Project: Homework 1
    File Description: This is the header file for the PString class.
*/

#pragma once

#include <iostream>

using namespace std;

class PString : public string {
    public:
        PString();
        PString(string word);
        bool isPalindrome();
};
/*  EncryptableString.h
    Author: Chris Adkins
    Module: 7
    Project: Homework 2
    File Description: This is the header file for the EncryptableString class.
    
*/

#pragma once
#include <string>

using namespace std;

class EncryptableString : public string {
    public:
        EncryptableString(string word);
        void encrypt();
};
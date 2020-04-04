#pragma once

#include <iostream>

using namespace std;

class PString : public string {
    public:
        PString();
        PString(string word);
        bool isPalindrome();
};
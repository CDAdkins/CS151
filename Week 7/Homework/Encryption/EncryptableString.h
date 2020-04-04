#pragma once
#include <string>

using namespace std;

class EncryptableString : public string {
    public:
        EncryptableString(string word);
        void encrypt();
};
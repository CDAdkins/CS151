#include "EncryptableString.h"
#include <iostream>

using namespace std;

int main() {
    // Initializing our encryptable strings.
    EncryptableString test1("Holy Moly!");
    EncryptableString test2("San Diego Zoo");
    EncryptableString test3("The cost is $25.89.");
    EncryptableString test4("Go away - unless you have tacos.");
    EncryptableString test5("No one can make you feel inferior without your consent.");

    
    // Printing Original Strings.
    cout << "\n\nOriginal Strings:\n";
    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;
    cout << test5 << endl;
    // Encrypting Strings.
    test1.encrypt();
    test2.encrypt();
    test3.encrypt();
    test4.encrypt();
    test5.encrypt();
    // Printing Encrypted Strings.
    cout << "\n\nEncrypted Strings:\n";
    cout << test1 << endl;
    cout << test2 << endl;
    cout << test3 << endl;
    cout << test4 << endl;
    cout << test5 << endl;

}
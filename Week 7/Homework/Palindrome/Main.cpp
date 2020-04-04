#include <iostream>
#include "PString.h"
#include <string>

using namespace std;

int main() {
    string userInput;
    

    // Test Cases.
    PString test1("Chic");
    PString test2("Book");
    PString test3("Kayak");
    PString test4("25 ABC 9cba52");
    PString test5("Don't nod");
    PString test6("Not even close!");
    PString test7("A man, a plan, a canal -- Panama");

    test1.isPalindrome();
    test2.isPalindrome();
    test3.isPalindrome();
    test4.isPalindrome();
    test5.isPalindrome();
    test6.isPalindrome();
    test7.isPalindrome();

    cout<<"\n\n-----------------------------------------\n| ";
    cout << "Welcome to the Palindrome Checker 3000|\n";
    cout << "-----------------------------------------\n\nEnter your word or phrase: ";
    getline(cin, userInput);
    PString input(userInput);
    input.isPalindrome();
}
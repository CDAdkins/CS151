/*  sequence.cpp
    Author: Chris Adkins
    Module: 12
    Project: Homework 2
    Problem Statement: 

    Algorithm:
        1. Create an abstract class for the base class called AbstractSeq.
            a. Create an abstract function called fun, this will determine what the class's sequence will look like.
            b. Create a function to print out the sequence as long as it is under a specified int.
            c. Create a function to print the sum of the sequence.
        2. Create a subclass of AbstractSeq with an overidden fun() to make a new sequence.
        3. Create another subclass with a different sequence.
        4. Print and show the sums of the two subclass sequences.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

class AbstractSeq {
    public:
        virtual int fun(int k) = 0;

        void printSeq(int k, int m) { // Function to print the 
            while (k <= m) {
                cout << k;
                k * 2 <= m ? cout << ", " : cout << "\n"; // Deciding whether to print a comma or a new line.
                k = fun(k); // Updating k's value before the next loop.
            }
        }

        void sumSeq(int k, int m) {
            static int sum = 0;
            while (k <= m) {
                sum += k;
                k = fun(k);
            }
            cout << sum << endl;
        }
};

class Double : public AbstractSeq { // Sequence that doubles each time.
    public:
        virtual int fun(int k) {
            return k * 2;
        }
};

class Wild : public AbstractSeq {
    public:
        virtual int fun(int k) {
            return (k / 2 * 5 + 5);
        }
};

int main() {
    Double dubSeq;
    Wild wildSeq;
    cout << "Double Sequence:\n";
    dubSeq.printSeq(1, 1000);
    dubSeq.sumSeq(1, 1000);
    cout << "\nWild Sequence:\n";
    wildSeq.printSeq(1, 1000);
    wildSeq.sumSeq(1, 1000);
}
#include <iostream>
using namespace std;

int main() {
    string empty = "  ____\n /    |\n      |\n      |\n      |\n  -------\n"; // Empty Gallows.
    string head = "  ____\n /    |\n0     |\n      |\n      |\n  -------\n";
    string body = "  ____\n /    |\n0     |\n|     |\n      |\n  -------\n";
    string rightArm = "  ____\n /    |\n 0    |\n/|    |\n      |\n  -------\n";
    string leftArm = "  ____\n /    |\n 0    |\n/|\\   |\n      |\n  -------\n";
    string rightLeg = "  ____\n /    |\n 0    |\n/|\\   |\n/     |\n  -------\n";
    string leftLeg = "  ____\n /    |\n 0    |\n/|\\   |\n/ \\   |\n  -------\n";
    string word = "Animal";

    string hangmen[] = {empty, head, body, rightArm, leftArm, rightLeg, leftLeg};


    cout << "\n\n";

    for (int i = 0; i < 7; i++) {
        cout << hangmen[i];
    }
    cout << endl;
}
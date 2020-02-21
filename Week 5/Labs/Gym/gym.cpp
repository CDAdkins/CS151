/*  gym.cpp
    Author: Chris Adkins
    Module: 5
    Project: Lab 1
    Problem Statement: 


    Algorithm:
        1. TODO

    Classes Needed:
        <iostream> - For printing to the user
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

struct Member {
    static int totalVisits;
    static int activeMembers;
    static int lastId;

    string name;
    char   type;
    int    id;
    int    visits;
        

    Member(string name, char type) {
      this->name = name ;
      this->type = type ;
      activeMembers++ ;
      id = lastId++ ;
    }

    ~Member() {
        activeMembers--;
    }
};

const double BASIC_RATE   = 28.50;
const double PREMIUM_RATE = 60.00;
int Member::totalVisits = 0;
int Member::activeMembers = 0;
int Member::lastId = 100000;

void visit(Member *member) {
    Member::totalVisits++;
}

int generateVisits(Member *member) {
    int randNum = ((rand() % 20 + 1 - 5) + 5);
    member->visits = randNum;
    for (int i = 0; i < member->visits; i++) {
        visit(member);
    }
}

int main() {
    vector<Member *> members;

    Member* oprah = new Member("Oprah Winfrey", 'P');
    Member* fluffy = new Member("Fluffy Iglesias", 'P');
    Member* charlie = new Member("Charlie Sheen", 'B');
    Member* bill = new Member("Bill Gates", 'B');

    members.push_back(oprah);
    members.push_back(fluffy);
    members.push_back(charlie);
    members.push_back(bill);

    members.erase(members.begin() + 2); // Erasing the pointer to charlie from the vector.
    delete charlie; // Deleting Charlie Sheen from the heap.

    srand(time(NULL));
    for (Member* i : members) {
        generateVisits(i);
    }
    
    cout << "\n  ID      Name             Visits    Rate" << endl;
    cout << "------  ----------------  --------  -------" << endl;
    for (Member* i : members) {
        cout << i->id << "\t" << i->name << "\t" << setw(7) 
        << right  << i->visits << "     ";
        if (i->type == 'B') {
            cout << "$" << setprecision(4) << BASIC_RATE << 0 << endl;
        } else {
            cout << "$" <<  PREMIUM_RATE << ".00" << endl;
        }
    }
    cout << "\nTotal Visits: " << Member::totalVisits << endl;
    cout << "Active Members: " << Member::activeMembers;
}
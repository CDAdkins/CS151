/*  gym.cpp
    Author: Chris Adkins
    Module: 5
    Project: Lab 1
    Problem Statement: This program tracks a gym's members and their time spent at the gym.

    Algorithm:
        1. Create a struct called Member with variables for name, type, id, and visits.
        2. Create a vector to hold Member pointers.
        3. Add the four members to the vector using push_back().
        4. Use the erase() function to remove charlie sheen from the vector.
        5. Use delete() to remove charlie sheen from the heap.
        6. Use srand to randomly generate the number of visits each member made to the gym.
        7. Use for loops and cout to print a list of the members to the user.

    Classes Needed:
        <iostream> - For printing to the user.
        <iomanip> - To format our list.
        <vector> - To hold and manipulate our members.
*/

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

struct Member { // Member structure.
    static int totalVisits; // Total number of visits made to the gym.
    static int activeMembers; // Total number of active members.
    static int lastId; // Number used to determine the ID of the next member.

    string name; // Name of the member.
    char   type; // B = Basic Membership, P = Premium Membership.
    int    id; // ID number.
    int    visits; // Number of times this member has visited the gym.
        

    Member(string name, char type) { // Constructor.
      this->name = name;
      this->type = type;
      activeMembers++; // Every time a member is created, increment the number of active members by one.
      id = lastId++; // Take the ID of the last member, increase it by one, apply that number to this member's ID.
    }

    ~Member() { // Destructor.
        activeMembers--; // When a member is removed, decrement the number of active members by one.
    }
};

const double BASIC_RATE   = 28.50; // Price per month for a basic membership.
const double PREMIUM_RATE = 60.00; // Price per month of a premium membership.
int Member::totalVisits   = 0; // Total number of visits made to the gym.
int Member::activeMembers = 0; // Total number of active members.
int Member::lastId        = 100000; // Number used to determine the ID of the next member.

void visit(Member *member) {
    Member::totalVisits++; // When the visit function is called, increment the total number of visits by one.
}

int generateVisits(Member *member) { // Randomly generate the number of visits a member makes in a month.
    int randNum = ((rand() % 20 + 1 - 5) + 5); // Generate an int between 1 and 20.
    member->visits = randNum; // Use the random int as the number od visits for this member.
    for (int i = 0; i < member->visits; i++) { // For every time the member visits the gym.
        visit(member); // Call the visit function for the member.
    }
}

int main() {
    vector<Member *> members; // Create an empty vector of member pointers.

    // Create our four member pointers.
    Member* oprah = new Member("Oprah Winfrey", 'P');
    Member* fluffy = new Member("Fluffy Iglesias", 'P');
    Member* charlie = new Member("Charlie Sheen", 'B');
    Member* bill = new Member("Bill Gates", 'B');

    // Add our member pointers to the vector.
    members.push_back(oprah);
    members.push_back(fluffy);
    members.push_back(charlie);
    members.push_back(bill);

    members.erase(members.begin() + 2); // Erasing the pointer to charlie from the vector.
    delete charlie; // Deleting Charlie Sheen from the heap.

    srand(time(NULL)); // Set our seed for srand.
    for (Member* i : members) { // For every member in our vector.
        generateVisits(i); // Generate a number of visits.
    }
    
    // Printing our table.
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
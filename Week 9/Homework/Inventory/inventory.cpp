/*  inventory.cpp
    Author: Chris Adkins
    Module: 9
    Project: 2
    Problem Statement: This program simulates an inventory system with add, view, and change functionality.

    Algorithm:
        1. Create a struct called item to represent an item in the inventory.
        2. Create an fstream for the text file that will hold our items.
        3. Display a menu to the user, informing them of their options.
        4. Create a switch statement to ask the user what they'd like to do with the inventory.
        5. If they choose 1, create an item based on the user's input. Add the item's variables line by line to the text file.
        6. If they choose 2, print the inventory text file to the user, describe what you are printing as you print the contents.
        7. If they choose 3, Use seekp to move to the user's chosen item, then write the new item's qualities into the text file.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    struct Item { // Our item struct.
        string description;
        int quantity;
        double wholesale;
        double retail;
        string dateAdded;
    };

    ofstream outFile("inventory.txt", ios::out | ios::app); // The stream for our inventory file.
    ifstream inFile("inventory.txt", ios::in);
    int choice = 0; // Int to represent the user's choice for the menu.

    cout << "Inventory Manager\n"; // Displaying the menu to our user.
    cout << "-----------------\n";
    cout << "1. Add New Records to the File.\n";
    cout << "2. Display Records from File.\n";
    cout << "3. Change Existing Records in File.\n";
    cout << "Please select an option: ";
    cin >> choice;

    switch(choice) {
        case 1: { // Add an item to the inventory.
            Item item; // Create a new item to add to the inventory;
            cout << "\nItem Description: ";
            cin >> item.description;
            cout << "Quantity on Hand: ";
            cin >> item.quantity;
            cout << "Wholsesale Price: $";
            cin >> item.wholesale;
            cout << "Retail Price: $";
            cin >> item.retail;
            cout << "Date Added to Inventory (MM/DD/YYYY): ";
            cin >> item.dateAdded;

            outFile << item.description << "\n" << item.quantity << "\n";
            outFile << item.wholesale << "\n" << item.retail << "\n";
            outFile << item.dateAdded << "\n";
            break;
        }
            
        case 2: { // Read items from the inventory.
            string line; // This is the line that we will read from the file.
            cout << "\nItems in Inventory:\n";
            cout << "-------------------\n";

            while (getline(inFile, line)) { // Runs as long as there are lines left in the file.
                cout << "Item: " << line << endl;
                getline(inFile, line);
                cout << "Quantity: " << line << endl;
                getline(inFile, line);
                cout << "Wholesale Price: $" << line << endl;
                getline(inFile, line);
                cout << "Retail Price: $" << line << endl;
                getline(inFile, line);
                cout << "Date Added: " << line << "\n\n";
            }
            break;
        }

        case 3: { // Change an item in the inventory.
            int count = 0; // To number the items in the inventory.

            string line; // This is the line that we will read from the file.
            cout << "\nItems in Inventory:\n";
            cout << "-------------------\n";

            while (getline(inFile, line)) { // Runs as long as there are lines left in the file.
                cout << count + 1 << ". " << line << endl;
                count++;
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);
                getline(inFile, line);
            }
            inFile.close();
            cout << "\nChoose an item: ";
            cin >> choice;

            outFile.close();
            outFile.open("inventory.txt", ios::in);
            outFile.seekp(31L, ios::beg);
            cout << "Item Description: ";
            cin >> line;
            outFile << line << endl;
            cout << "Quantity: ";
            cin >> line;
            outFile << line << endl;
            cout << "Wholesale Price: ";
            cin >> line;
            outFile << line << endl;
            cout << "Retail Price: ";
            cin >> line;
            outFile << line << endl;
            cout << "Date Added: ";
            cin >> line;
            outFile << line << endl;
            outFile.close();

            break;
        }
    }
}
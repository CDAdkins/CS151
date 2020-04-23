#include <fstream>
#include <iostream>

using namespace std;

int main() {
    struct Item {
        string description;
        int quantity;
        double wholesale;
        double retail;
        string dateAdded;
    };

    ofstream outFile("inventory.txt", ios::out | ios::app); // The stream for our inventory file.
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
            cout << "Item Description: ";
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
            outFile << item.wholesale << "\n" << item.wholesale << "\n";
            outFile << item.retail << "\n" << item.dateAdded << ",\n";
            break;
        }
            
        case 2: 
            cout << "help";
            break;
    }
}
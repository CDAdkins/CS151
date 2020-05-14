/*  LinkedList.cpp
    Author: Chris Adkins
    Module: 14
    Project: Homework #1, 3, 6, 7, 8.
    Problem Statement: This program implements a simple linked list class.

    Algorithm:
        1. Create a linked list class.
            a. Create a Node class.
                I. Create a double to hold the node's values.A
                II. Create a Node pointer pointing to the next Node.
            b. Create Node pointers for the head and tail Nodes.
            c. We don't need a constructor because we don't need to initialize anything immediately.
            d. Create a getSize() function that returns size.
            e. Create a print function that walks throught the list and prints each node's index and value.
            f. Create a reverse function.
                I. Initialize three pointers, prev, current, and next.
                II. Walk through the linked list.
                III. next = current->next.
                IV. current->next = prev.
                V. prev = current and current = next. Repeat.
            g. Create a search function that walks through the list and returns a Node's index if its value matches the search.
            h. Create an insert function that calls the add() function if the index is 0.
                I. Walk through the list until you rach the index where you'll insert the new Node.
                II. Set temp = current->next and current->next = newNode.
                III. Set newNode->next = temp.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>
using namespace std;

struct Node { // Node struct
    double value;
    Node *next;

    Node() { // No Arg Constructor
        next = nullptr;
    }

    Node(double data) { // Constructor with an argument for the data.
        next = nullptr;
        value = data;
    }
};

class LinkedList {
    private:
    Node *head = nullptr; // First Node in the list.
    Node *tail = nullptr; // Last Node in the list.
    int size = 0; // Number of nodes in the list.

    public:
    // Size getter.
    int getSize() {
        return size;
    }

    // Function to display the contents of the list.
    void print() {
        if (size == 0)
            cout << "Empty List\n";

        Node *current = head;
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "] " << current->value << endl;
            current = current->next;
        }
    }

    // Add double to the head of the list.
    void add(double num) {
        Node *newNode = new Node(num); // Create a new node.
        newNode->next = head; // Set the newNode's next to the head.
        head = newNode; // Point the head pointer at newNode.
        size++; // Increment the size of the list.

        if (tail == nullptr) { // If we do not have a tail.
            tail = head; // Set the tail pointer to the head pointer.
        }
    }

    // Returns whether or not the list contains a specific value.
    bool isMember(double num) {
        Node *current = head;
        for (int i = 0; i < size; i++) {
            if (current->value == num) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to reverse the order of the elements in the list.
    void reverse() {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;

        while (current != NULL) {
            next = current->next; // Store our next variable.
            
            current->next = prev; // Reverse the current nodes pointer.
            // Move the pointers one position forward.
            prev = current;
            current = next;
        }
        head = prev;
        
        current = head;
        for (int i = 0; i < size-1; i++) { // Setting the tail.
            tail = current->next;
            current = current->next;
        }
    }

    // Function to search for a number in the list.
    int search(double num) {
        Node *current = head;

        for (int i = 0; i < size; i ++) {
            if (current->value == num) { // If we find the number.
                return i;
            }
            current = current->next;
        }
        return -1;
    }

    void insert(double num, int pos) {
        Node *current = head;
        Node *newNode = new Node(num);
        Node *temp;
        if (pos == 0) { // If we want to add at the beginning, call the add function.
            add(num);
        } else if (pos == size) { // If we are adding the element to the end of the list.
            tail->next = new Node(num);
            tail = tail->next;
            size++;
            
        } else {
            for (int i = 0; i < size; i++) {
                if (i == pos - 1) {
                    temp = current->next;
                    current->next = newNode;
                    newNode->next = temp;
                    size++;
                }
                current = current->next;
            }
        }
    }
};

int main() {
    LinkedList list;

    list.add(7.0);
    list.add(8.0);
    list.add(9.0);

    cout << "List after adding 7, 8 and 9: " << endl;
    list.print();

    cout << "\nlist.isMember(9): ";
    cout << list.isMember(9) << endl;
    cout << "list.isMember(7): ";
    cout << list.isMember(7) << endl;
    cout << "list.isMember(5): ";
    cout << list.isMember(5) << endl;

    cout << endl;

    list.reverse();

    cout << "After calling list.reverse(): " << endl;
    list.print();

    cout << "\nlist.search(8): " << endl;
    cout << list.search(8) << endl;
    cout << "list.search(200): " << endl;
    cout << list.search(200) << endl;

    cout << "\nInserting 55 at index 1: " << endl;
    list.insert(55, 1);
    list.print();
}
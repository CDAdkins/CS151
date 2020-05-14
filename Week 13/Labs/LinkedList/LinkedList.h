/* LinkedList.h - Generic class allowing representation of a linked list
 * Author:     Chris Merrill
 * Module:     13
 * Project:    Lab
 * Problem statement:  This file contains the definition for a generic
 *    Node class and a generic LinkedList class.  Enhance an generic LinkedList.h
 *    class with several functions to make the class more usable.
 *
 *    Functions should throw a run-time exception if there would be confusion between
 *    what is returned (successful) and something couldn't be returned.
 *
 * Algorithm:
 *    Classes already included are  Node<T> and LinkedList<T>
 *    Functions already given are:  full constructor, addFirst, addLast, add,
 *        getFirst, getLast(), get, indexOf, getSize, isEmpty, removeFirst,
 *        removeLast, and clear
 *
 *    Functions to be written are:
 *        display, remove, removeAt, find, findLast, contains, and set
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>                          // catch run-time errors
using namespace std ;

/******************************
 *                            *
 *  Template for Node class   *
 *                            *
 ******************************/
template<class T>
class Node {
    public:
        T data ;                // value or object stored in the node
        Node<T> *next ;         // pointer to the next node

    // No-arg constructor
    Node() {
        next = nullptr  ;
    }

    // Constructor with one parameter
    Node(T myData) {
        this->data = myData ;   // stores value in node's data field
        next = nullptr ;
    }
} ;

/*****************************************
 *                                       *
 *   Template for the LinkedList class   *
 *                                       *
 *****************************************/
template<class T>
class LinkedList {

    private:
        Node<T> *head, *tail ;         // pointers to first and last nodes
        int size ;                       // number of nodes in this list

    public:

        // Prototypes of functions already present
        LinkedList() ;                           // constructor

        void addFirst(T myData) ;                // add an element to the list
        void addLast(T myData) ;
        void add(int index, T myData) ;

        T getFirst() ;                           // accessors
        T getLast() ;
        T get(int index) ;
        int indexOf(T myData) ;
        int getSize() ;
        bool isEmpty() ;

        T removeFirst() throw (runtime_error) ;  // remove an element or clear
        T removeLast() throw (runtime_error) ;
        void clear() ;

        // Function prototypes to be provided in this lab
        bool contains(T myData);       // done
        int lastIndexOf(T myData);     // done
        bool remove(T myData);         // done
        T removeAt(int index);         // done
        bool set(int index, T myData); // done
        void display();
} ;

/************************************
*                                   *
*     Function implementations      *
*                                   *
*************************************/

// Find an element in the list by value.
template<typename T>
bool LinkedList<T>::contains(T myData) { // Determines if the list contains a specific element.
    Node<T> *current = head ; // Represents current node.
    for (int i = 0 ; i < size; i++) { // Iterate over the list.
        if (current->data == myData) { // If the current node's data is equal to the argument.
            return true;
        }
        current = current->next; // Move to the next Node.
    }
    return false;
}

// Return the index of the last occurance 
template<typename T>
int LinkedList<T>::lastIndexOf(T myData) { // Return the last index of the specified data element.
    Node<T> *current = head ; // Represents current node.
    int lastIndex = -1;
    for (int i = 0 ; i < size; i++) { // Iterate over the list.
        if (current->data == myData) { // If the current node's data is equal to the argument.
            lastIndex = i; // Update lastIndex but don't return yet.
        }
        current = current->next; // Move to the next Node.
    }
    return lastIndex;
}

// Remove an element given its data.
template<typename T>
bool LinkedList<T>::remove(T myData) { // Remove element with specific data.
    Node<T> *prev = head ;             // create new ptr temp - point to same place as head
    Node<T> *current = head->next;

    if (head->data == myData) { // If the head matches the data we're looking for.
        removeFirst(); // Call the removeFirst() function.
        return true;
    } else if (tail->data == myData) { // If the tail's data matches our data.
        removeLast(); // Call the removeLast() function.
        return true;
    } else {
        for (int i = 0; i < size - 1; i ++) { // Iterate over the list.
            if (current->data == myData) { // If the current matches the search parameters.
                prev->next = current->next; // Unlink the Node current is pointing to.
                size--;

                delete current;
                return true;
            }
        current = current->next; // Increment current.
        prev = prev->next; // Increment prev.
        }
    }

    delete current;
    return false;
}

// Remove an element given its index.
template<typename T>
T LinkedList<T>::removeAt(int index) {
    Node<T> *prev = head ;             // create new ptr temp - point to same place as head
    Node<T> *current = head->next;
    T temp;

    if (index < 0 || index >= size) {
        throw runtime_error("Invalid index");
    } else if (index == 0) { // If the head matches the data we're looking for.
        temp = head->data;
        removeFirst(); // Call the removeFirst() function.
        return temp;
    } else if (index == size - 1) { // If the tail's data matches our data.
    temp = tail->data;
        removeLast(); // Call the removeLast() function.
        return temp;
    } else {
        for (int i = 1; i < size - 1; i ++) { // Iterate over the list.
            if (i == index) { // If the current index matches our search index.
                temp = current->data;
                prev->next = current->next; // Unlink the Node current is pointing to.
                size--;

                delete current;
                return temp;
            }
        current = current->next; // Increment current.
        prev = prev->next; // Increment prev.
        }
    }
}

template<typename T>
bool LinkedList<T>::set(int index, T myData) {
    Node<T> *current = head; // Node pointer to walk the list with.

    if (index < 0 || index > size) { // If the index is out of range.
        return false;
    }

    for (int i = 0; i < size; i++) { // Iterate over the list.
        if (i == index) {
            current->data = myData; // Setting our current element's data equal to myData.
            return true;
        }
        current = current->next; // Moving our current pointer up one element.
    }
    return false;
}

template<typename T>
void LinkedList<T>::display() {
    Node<T> *current = head; // pointer to walk throught the list.

    for (int i = 0; i < size; i++) {
        cout << "\n[" << i << "]" << " " << current->data; // Print the index as well as the data.
        current = current->next;
    }
    cout << endl;
}

// Constructor
template<typename T>
LinkedList<T>::LinkedList() {                    // An empty list
    head = tail = nullptr ;
    size = 0 ;
}

// Add node to beginning of the list
template<typename T>
void LinkedList<T>::addFirst(T myData) {
    Node<T> *newNode = new Node<T>(myData) ;    // Create new node and ptr
    newNode->next = head ;                      // Assign value of head ptr to next ptr of new node
    head = newNode ;                            // Set head to point at new node
    size++ ;                                    // increment size of LinkedList

    if (tail == nullptr)
        tail = head ;                           // set tail ptr to new node if list was empty
}

// Add node to the end of the list
template<typename T>
void LinkedList<T>::addLast(T myData) {
    if (tail == nullptr) {                      // list is empty
        head = tail = new Node<T>(myData) ;     // point head and tail to new node
    } else {
        tail->next = new Node<T>(myData) ;      // create new node
        tail = tail->next ;                     // set tail ptr to new node
    }

    size++ ;
}

// Add node at specific index
template<typename T>
void LinkedList<T>::add(int index, T myData) {
    if (index == 0) {                           // add node at beginning of list
        addFirst(myData) ;
    } else if (index >= size) {                 // add node at end of list
        addLast(myData) ;
    } else {                                    // insert this element between two nodes
        Node<T> *current = head ;               // loop to node before this one
        for (int i = 1 ; i < index ; i++)
            current = current->next ;
        Node<T> *temp = current->next ;         // one after this one
        current->next = new Node<T>(myData) ;
        (current->next)->next = temp ;
        size++ ;
    }
}

// Get data from first node
template<typename T>
T LinkedList<T>::getFirst() {
    if (size == 0) {
        throw runtime_error("Index out of range") ; // no nodes in the list
    } else {
        return head->data ;                     //retrieve value in first node
    }
}

// Get data from last node
template<typename T>
T LinkedList<T>::getLast() {                    // no nodes in the list
    if (size == 0) {
        throw runtime_error("Index out of range") ; // retrieve value in last node
    } else {
        return tail->data ;
    }
}

// Get node at the specific index
template<typename T>
T LinkedList<T>::get(int index) {
    if (index < 0 || index > size - 1)
        throw runtime_error("Index out of range") ;

    Node<T> *current = head ;                // walk list
    for (int i = 0 ; i < index ; i++)
        current = current->next ;            // point to next node

    return current->data ;                   // get value if found
}

// Get the index of a specific node
template<typename T>
int LinkedList<T>::indexOf(T myData) {
    Node<T> *current = head ;
    for (int i = 0 ; i < size ; i++) {
        if (current->data == myData)        // walk list to find value
            return i ;
        current = current->next ;
    }
    return -1 ;                             // return -1 if value not found
}


// Get the number of nodes in the list (number added - number removed)
template<typename T>
int LinkedList<T>::getSize() {
    return size ;
}

// Remove first node from list
template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error) {
    if (size == 0) {
        throw runtime_error("No nodes in the list") ;
    } else {
        Node<T> *temp = head ;             // create new ptr temp - point to same place as head
        head = head->next ;                // point to the next object beyond the first
        size-- ;
        if (head == nullptr) {
            tail = nullptr ;
        }
        T myData = temp->data ;
        delete temp ;                      // delete node temp is pointing to
        return myData ;                    // may or may not use this value
    }
}

// Remove last node from the list
template<typename T>
T LinkedList<T>::removeLast() throw (runtime_error) {
    if (size == 0) {
        throw runtime_error("No nodes in the list") ;
    } else if (size == 1) {
        Node<T> *temp = head ;
        head = tail = nullptr ;
        size = 0 ;
        T myData = temp->data ;
        delete temp ;                          // delete node temp is pointing to
        return myData ;                        // may or may not use this value
    } else {
        Node<T> *current = head ;              // set current to point at what head points at
        for (int i = 0 ; i < size - 2 ; i++)   // walk list moving current ptr to end
            current = current->next ;

        Node<T> *temp = tail ;
        tail = current ;
        tail->next = nullptr ;
        size-- ;
        T myData = temp->data ;
        delete temp ;
        return myData ;
    }
}

// Clear the list - takes time but frees up memory
template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {          // if still a node in list
        Node<T> *temp = head ;         // set temp ptr to what head points at
        head = head->next ;            // point head at next node
        delete temp ;                  // delete the node temp is pointing to
    }
    head = tail = nullptr ;            // the empty list
    size = 0 ;
}

// See if the list is empty
template<typename T>
bool LinkedList<T>::isEmpty() {
    cout << "in isEmpty(), size is now " << size ;
    return head == nullptr ;                   // no nodes in list
}

#endif

/* PersonAtMCC.cpp - Function definitions for parent class
 * Author:     Chris Adkins
 * Module:     7
 * Project:    Lab, Part 1
 * Description:  Function definitions for parent class
 */

#include "PersonAtMCC.h"
#include <iostream>
using namespace std ;

/**** WRITE THE MISSING CONSTRUCTORS, USE MEMBER INITIALIZATION ****/

PersonAtMCC::PersonAtMCC() {
    this->id = 10000000;
    this->name = "John Doe";
    this->address = "Parts Unknown";
    this->phone = "No Number On Record";
}

PersonAtMCC::PersonAtMCC(long ID, string name) {
    this->id = 10000000;
    this->name = name;
    this->address = "Parts Unknown";
    this->phone = "No Number On Record";
}

PersonAtMCC::PersonAtMCC(long ID, string name, string address, string phone) {
    this->id = ID;
    this->name = name;
    this->address = address;
    this->phone = phone;
}

// getters and setters
long PersonAtMCC::getId() {
    return id ;
}

string PersonAtMCC::getName() {
    return name ;
}

string PersonAtMCC::getAddress() {
    return address ;
}

string PersonAtMCC::getPhone() {
    return phone ;
}

// Setters
void PersonAtMCC::setId(long new_id) {
    id = new_id ;
}

void PersonAtMCC::setName(string new_name) {
    name = new_name ;
}

void PersonAtMCC::setAddress(string new_address) {
    address = new_address ;
}

void PersonAtMCC::setPhone(string new_phone) {
    phone = new_phone ;
}

void PersonAtMCC::showInfo() {
    cout << "ID: " << PersonAtMCC::getId() << "  Name: " << PersonAtMCC::getName() << "  Address: " << PersonAtMCC::getAddress() << endl;
    cout << "Phone: " << PersonAtMCC::getPhone() << "\n" << endl;
}

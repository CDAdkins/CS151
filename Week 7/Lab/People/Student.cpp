/* Student.cpp - Function definitions for Student class, child of PersonAtMCC
 * Author:     Chris Adkins
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Student.h"
#include <iostream>
using namespace std ;

Student::Student(long ID, string name, string address, string phone, string major, int credits_received, bool applied_to_4_year, bool is_veteran) {
    PersonAtMCC::setId(ID);
    PersonAtMCC::setName(name);
    PersonAtMCC::setAddress(address);
    PersonAtMCC::setPhone(phone);
    this->major = major;
    this->credits_received = credits_received;
    this->applied_to_4_year = applied_to_4_year;
    this->is_veteran = is_veteran;
}

// Getters for this class only
string Student::getMajor() {
    return major ;
}

int Student::getCreditsReceived() {
    return credits_received ;
}

bool Student::getAppliedTo4Year() {
    return applied_to_4_year ;
}

bool Student::getIsVeteran() {
    return is_veteran ;
}

// Setters
void Student::setMajor(string new_major) {
    major = new_major ;
}

void Student::setCreditsReceived(int new_credits_received) {
    credits_received = new_credits_received ;
}

void Student::setAppliedTo4Year(bool new_has_applied) {
    applied_to_4_year = new_has_applied ;
}

void Student::setIsVeteran(bool new_is_veteran) {
    is_veteran = new_is_veteran ;
}

void Student::showInfo() {

    cout << "ID: " << PersonAtMCC::getId() << "  Name: " << PersonAtMCC::getName() << "  Address: " << PersonAtMCC::getAddress() << endl;
    cout << "Phone: " << PersonAtMCC::getPhone() << endl;
    cout << "Major: " << major << "  Credits: " << credits_received << "  4-year?: " << applied_to_4_year << "  Veteran?: " << is_veteran << "\n" << endl;
}



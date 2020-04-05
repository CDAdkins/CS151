/* Instructor.cpp - Definition of functions for the Instructor subclass to PersonAtMCC
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Instructor.h"
#include <iostream>
using namespace std ;

Instructor::Instructor(long ID, string name, string address, string phone, string department, bool is_permanent, double pay_rate, double hours) {
    PersonAtMCC::setId(ID);
    PersonAtMCC::setName(name);
    PersonAtMCC::setAddress(address);
    PersonAtMCC::setPhone(phone);
    this->department = department;
    this->is_permanent = is_permanent;
    this->pay_rate = pay_rate;
    this->hours = hours;
}

// Getters for this class only
string Instructor::getDepartment() {
    return department ;
}

bool Instructor::getIsPermanent() {
    return is_permanent ;
}

double Instructor::getPayRate() {
    return pay_rate ;
}

// Setters for this class only
void Instructor::setDepartment(string new_department) {
    department = new_department ;
}

void Instructor::setIsPermanent(bool new_is_permanent) {
    is_permanent = new_is_permanent ;
}

void Instructor::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

void Instructor::showInfo() {
    cout << "ID: " << PersonAtMCC::getId() << "  Name: " << PersonAtMCC::getName() << "  Address: " << PersonAtMCC::getAddress() << endl;
    cout << "Phone: " << PersonAtMCC::getPhone() << endl;
    cout << "Department: " << department << "  Permanent?: " << is_permanent << "  Pay-Rate: " << pay_rate
    << "  Hours: " << hours << "\n" << endl;

}

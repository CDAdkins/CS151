/* Movie.cpp - Implementation of the Movie class
 * Author:   Chris Merrill
 * Module    4
 * Project:   Review Exercise
 *
 * Methods:
 *      No-arg constructor
 *      Full constructor
 *      getters and setters for all instance variables
 */

#include "Movie.h"
#include <iostream>
using namespace std ;

Movie::Movie() {
    setTitle("(none)") ;
    setYear(0) ;
    setRevenue(0.0) ;
}

Movie::Movie(string title, int year, double revenue) {
    setTitle(title) ;
    setYear(year) ;
    setRevenue(revenue) ;
}

string Movie::getTitle() {
    return title ;
}

int Movie::getYear() {
    return year ;
}

double Movie::getRevenue() {
    return revenue ;
}

void Movie::setTitle(string title) {
    this->title = title ;
}

void Movie::setYear(int year) {
    this->year = year ;
}

void Movie::setRevenue(double revenue) {
    this->revenue = revenue ;
}


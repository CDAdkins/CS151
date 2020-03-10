/*  TimeDate.cpp
    Author: Chris Adkins
    Module: 6
    Project: Exercise 2
    Problem Statement: This program creates a class called TimeDate and Event. It then displays the functionality to the user.


    Algorithm:
        1. Create a class called TimeDate.
            a. Create private variables for minutes, hours, days and months.
            b. Create a constructor with all of the previously mentioned variables.
            c. Create a function to return info about the TimeDate object as a string.
        2. Create a class called Event.
            a. Create two private TimeDate objects as well as a string variable called description.
            b. Create a constructor.
            c. Create a function to return information regarding the event as a string.
        3. In the main function, create two Events and print the information to the user.

    Classes Needed:
        <iostream> - For printing to the user.
*/

#include <iostream>

using namespace std;

class TimeDate { // Class holding information regarding a particular time and date.
    private:
        int   minute;
        int     hour;
        int      day;
        string month;

    public:
        TimeDate(int minute, int hour, int day, string month):
            minute(minute),
            hour(hour),
            day(day),
            month(month){};
        
        string getTimeDate() { // Function to return the date and time as a string.
            string print_hour = to_string(hour);
            string am_pm = (hour < 12 ? "am" : "pm"); // If the hour is less than 12, set var to am, else pm.
            if (hour == 0)
                print_hour = "12";
            if (hour > 12)
                print_hour = to_string(hour - 12);
            return month + " " + to_string(day) + " at " + print_hour + ":" + (minute < 10 ? "0" : "") + to_string(minute) + am_pm;
        }
};

class Event {
    private:
        TimeDate start_time, end_time;  
        string description;

    public: // Constructor
        Event(int start_hour, int start_minute, int start_day, string start_month, 
            int end_hour, int end_minute, int end_day, string end_month, string description): 
            start_time(start_minute, start_hour, start_day, start_month),
            end_time(end_minute, end_hour, end_day, end_month),
            description(description){};

        string getEvent() { // Return information regarding the event.
            return description + " starts on " + start_time.getTimeDate() +", ends on " + end_time.getTimeDate();
        }
};

int main() {
    Event sacrifice(17, 30, 14, "Oct.", 20, 30, 14, "Oct.", "Human Sacrifice"); // Creating our first event.
    Event fight(7, 30, 20, "Dec", 10, 0, 20, "Dec", "Team Cagefighting Match"); // Creating our second event.
    cout << sacrifice.getEvent() << endl;
    cout << fight.getEvent() << endl;
}
// setter and getters

// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <iomanip> 
#include "Time.h"
using namespace std;

bool getTimeFromUser(Time& time){
    // create string variable called input
    string input;
    // take in user input and store in input variable
    getline(cin, input);

    // check if input length is not 8
    if (input.length() != 8){
        cout << "Enter time in proper format (HH:MM:SS)!" << endl;
        return 0;
    }

    // create int variable called hour to store hour value
    int hour = atoi((input.substr(0,2).c_str()));
    // check if hour is not in range [0,23]
    if(hour < 0 || hour > 23){
        return false;
    }
    // use setHour function to set time's hour to value of hour
    time.setHour(hour);

    // create int variable called minutes to store minutes value
    int minutes = atoi((input.substr(3,2).c_str()));
    // check if minutes is not in range [0,59]
    if(minutes < 0 || minutes > 59){
        return false;
    }
    // use setMinutes function to set time's minutes to value of minutes
    time.setMinutes(minutes);

    // create int variable called seconds to store seconds value
    int seconds = atoi((input.substr(6,2).c_str()));
    // check if seconds is not in range [0,59]
    if(seconds < 0 || seconds > 59){
        return false;
    }
    // use setSeconds function to set time's seconds to value of seconds
    time.setSeconds(seconds);

    return true;
}

void print24Hour(Time time){
    // print with 0 in beginning if value is one digit
    // each time variable should have two places
    cout << setfill('0') << setw(2) << time.getHour() << ":";
    cout << setfill('0') << setw(2) << time.getMinutes() << ":";
    cout << setfill('0') << setw(2) << time.getSeconds();
    
}

int main(){
    // create time variable called start_time
    Time start_time;

    // prompt user to enter start time of lecture
    cout << "Enter the start time for the lecture (format is HH:MM:SS): ";
    // if start time is not valid, let user know and stop program
    if (getTimeFromUser(start_time) == false){
        cout << "The start time entered is invalid!" << endl;
        return 0;
    }
    
    // create time variable called end_time
    Time end_time;
    // prompt user to enterend time of lecture
    cout << "Enter the end time for the lecture (format is HH:MM:SS): ";
    // if end time is not valid, let user know and stop program
    if (getTimeFromUser(end_time) == false){
        cout << "The end time entered is invalid!" << endl;
        return 0;
    }

    // print out lecture start time and end time
    cout << "The lecture starts at ";
    print24Hour(start_time);
    cout << " and ends at ";
    print24Hour(end_time);
    cout << endl;

    return 0;
}
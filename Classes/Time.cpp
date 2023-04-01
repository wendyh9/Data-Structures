// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "Time.h"

using namespace std;

// define custom constructor 
Time::Time(int hour, int minutes, int seconds){
    this-> hour = hour;
    this-> minutes = minutes;
    this-> seconds = seconds;
}

// define default constructor
Time::Time(){
    Time(0,0,0);
}

// define copy constructor
Time::Time(Time& other){
    this-> hour = other.hour;
    this-> minutes = other.minutes;
    this-> seconds = other.seconds;
}

// define deconstructor
Time::~Time(){

}

// define accessor functions
int Time::getHour(){
    return hour;
}
int Time::getMinutes(){
    return minutes;
}
int Time::getSeconds(){
    return seconds;
}

// define mutator functions
void Time::setHour(int hour){
    this->hour = hour;
}
void Time::setMinutes(int minutes){
    this->minutes = minutes;
}
void Time::setSeconds(int seconds){
    this->seconds = seconds;
}

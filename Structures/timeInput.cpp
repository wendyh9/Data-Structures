// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

struct Time{
    // create int variable for each time place
    int hour;
    int minutes;
    int seconds;

    // default constructor
    // initialize hour, minutes, and seconds to 0
    Time(){
        hour = 0;
        minutes = 0;
        seconds = 0; 
    }

    // custom constructor
    // initialize hour, minutes, and seconds with int values that are given
    Time(int hour, int minutes, int seconds){
        this -> hour = hour;
        this -> minutes = minutes;
        this -> seconds = seconds;
    }

    // copy constructor
    // initialize hour, minutes, and seconds to other's hour, minutes, and seconds respectively
    Time(const Time& other){
        hour = other.hour;
        minutes = other.minutes;
        seconds = other.seconds;
    }

    // deconstructor
    // release memory used by time variable
    ~Time(){

    }
};

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

    // where to start looking for colon
    int start_index = 0;

    // string that will be converted to int
    string chunk;

    // index of where chunk should start from input
    int chunk_start = 0;
 
    for (int i = 0; i < 3; i++){
        // use substr() to get characters stored in chunk
        chunk = input.substr(chunk_start, 2);

        // increment chunk_start by 3
        chunk_start += 3;

        // first iteration
        if (i == 0){
            // 0-23
            // convert chunk to int and store as hour
            time.hour = atoi(chunk.c_str());
            // check if hour fits in [0,23] range
            if (time.hour < 0 || time.hour > 23){
                return false;
            }
        }

        // second iteration
        if (i == 1){
            // 0-59
            // convert chunk to int and store as minutes
            time.minutes = atoi(chunk.c_str());
            // check if minutes fits in [0,59] range
            if (time.minutes < 0 || time.minutes > 59){
                return false;
            };
        }

        // third iteration
        if (i == 2){
            // 0-59
            // convert chunk to int and store as seconds
            time.seconds = atoi(chunk.c_str());
            // check if minutes is in [0,59] range
            if (time.seconds < 0 || time.seconds > 59){
                return false;
            }
        }
    }
    return true;

}

void print24Hour(Time time){
    // print with 0 in beginning if value is one digit
    // each time variable should have two places
    cout << setfill('0') << setw(2) << time.hour << ":";
    cout << setfill('0') << setw(2) << time.minutes << ":";
    cout << setfill('0') << setw(2) << time.seconds;
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
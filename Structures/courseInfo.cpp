// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <assert.h> 
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

bool getTimeFromUser(Time& time, string input){

    // check if input length is not 8
    if (input.length() != 8){
        cout << "Enter time in proper format (HH:MM:SS)!" << endl;
        // cout << "input: " << input << endl;
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
    // create string variable to hold am/pm
    string day_or_night;
    // if hour is less than 13 -> morning
    if (time.hour < 13){
        day_or_night = "am";
        // if hour == 0 => 12 am
        if (time.hour == 0){
            time.hour = 12;
        }
    }
    // otherwise -> afternoon
    // need to adjust hour for printing
    else{
        time.hour = time.hour - 12;
        day_or_night = "pm";
    }    
    
    // print with 0 in beginning if value is one digit
    // each time variable should have two places
    cout << setfill('0') << setw(2) << time.hour << ":";
    cout << setfill('0') << setw(2) << time.minutes << ":";
    cout << setfill('0') << setw(2) << time.seconds << day_or_night;
}

struct Course{
    // create a variable for each appropriate parameter of Course struct
    string name;
    int credits;
    bool majorRequirement;
    double avgGrade;
    string days;
    Time start_time;
    Time end_time;

    // default constructor
    // initialize each variable so they have values when none are provided
    Course(){
        name  = "";
        credits = 0;
        majorRequirement = false;
        avgGrade = 0;
        days = "";
        start_time;
        end_time;
    }

    // custom constructor
    // assign each variable to its respective value when user provides values for Course struct
    Course(string name, int credits, bool majorRequirement, double avgGrade, string days, Time start_time, Time end_time){
        this -> name = name;
        this -> credits = credits;
        this -> majorRequirement = majorRequirement;
        this -> avgGrade = avgGrade;
        this -> days = days;
        this -> start_time = start_time;
        this -> end_time = end_time; 
    }
    
    // copy constructor
    // assign each value to its respective value from the address of other
    Course(const Course& other){
        name = other.name;
        credits = other.credits;
        majorRequirement = other.majorRequirement;
        avgGrade = other.avgGrade;
        days = other.days;
        start_time = other.start_time;
        end_time = other.end_time;
    }
    
    // destructor
    // release memory used by Course struct
    ~Course(){

    }

};

void printCourses(){
    // create an ifstream object called input
    ifstream input;

    // open file that will be read
    // use open method of ifstream object to open in.txt 
    input.open("in.txt");

    // if input is unable to be opened, an error will be raised
    assert(!input.fail());

    // create int variable to hold value of number of courses, initialize to 0
    int num_of_courses = 0;

    // get first line from the file (priming the input statement and storing value in num_of_courses)
    input >> num_of_courses;


    cout << "−−−−−−−−−−−−−−−−−−−" << endl;
    cout << "SCHEDULE OF STUDENT" << endl; 
    cout << "−−−−−−−−−−−−−−−−−−−" << endl;

    // no courses
    if (num_of_courses == 0){
        return;
    }

    // create Course variable called course
    Course course;
    // create string variable called line, used to store each line of in.txt
    string line;
    // test using getline before for loop
    getline(input, line);

    // create for loop, iterate num_of_courses + 1 times 
    for (int i = 1; i < num_of_courses + 1; i++){
        // get current line of input and store in line
        getline(input, line);
        // store line as course name
        course.name = line;

        // get current line of input and store in line
        getline(input, line);
        // convert line as an array of characters to int and store in course credits
        course.credits = atoi(line.c_str());

        // get current line of input and store in line
        getline(input, line);
        // convert line as an array of characters to int and store in course majorRequirement 
        course.majorRequirement = atoi(line.c_str());

        // get current line of input and store in line  
        getline(input, line);
        // convert line as an array of characters to float and store in course avgGrade
        course.avgGrade = atof(line.c_str());
        
        // get current line of input and store in line
        getline(input, line);
        course.days = line;
        
        getline(input, line);
        // create substr from index 0 using 8 characters, assign to line
        line = line.substr(0,8);
        // create Time variable called start_time
        Time start_time;
        // use getTimeFromUser to store info in start_time or determine if info is not valid
        getTimeFromUser(start_time, line);
        // assign start_time to course start_time
        course.start_time = start_time;

        
        // get current line of input and store in line
        getline(input, line);
        // create substr from index 0 using 8 characters, assign to line
        line = line.substr(0,8);
        // create Time variable called end_time
        Time end_time;
        // use getTimeFromUser to store info in end_time or determine if info is not valid
        getTimeFromUser(end_time, line);
        // assign end_time to course end_time
        course.end_time = end_time;


        // print out each variable in course
        cout << "COURSE " << i << ": " << course.name << endl;
        if (course.majorRequirement == 1){
            cout << "NOTE: this course is a major requirement!" << endl;
        }
        else{
            cout << "NOTE: this course is not a major requirement..." << endl;
        }
        cout << "Number of credits: " << course.credits << endl;
        cout << "Days of Lectures: " << course.days << endl;
        cout << "Lecture time: ";
        // use print24Hour for start_time and end_time because they are Time variables
        print24Hour(course.start_time);
        cout << " - ";
        print24Hour(course.end_time);
        cout << endl;
        cout << "Stat: on average students get " << course.avgGrade;
        printf("%% in this course");
        cout << endl;
        cout << "−−−−−−−−−−−−−−−−−−−" << endl; 
    }


    // close input file
    input.close();
    // check if file closed successfully
    assert(!input.fail());
}

int main(){
    // call printCourses function to print out course schedule
    printCourses();

    return 0;
}
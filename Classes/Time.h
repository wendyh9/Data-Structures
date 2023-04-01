// author: Wendy Haw
// collaborators: none

#ifndef TIME_H
#define TIME_H

class Time{
    private:
        int hour;
        int minutes;
        int seconds;

    public:
        // custom constructor declaration
        Time(int hour, int minutes, int seconds);

        // default constructor declaration
        Time();

        // copy constructor declaration
        Time(Time& other);

        // destructor declaration
        ~Time();

        // declared accessor functions
        int getHour();
        int getMinutes();
        int getSeconds();

        // declared mutator functions
        void setHour(int hour);
        void setMinutes(int minutes);
        void setSeconds(int seconds);

};

#endif


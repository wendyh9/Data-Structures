// author: Wendy Haw
// collaborators: none

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

using namespace std;

// create Stack class and inherit public members from LinkedList class
class Stack : public LinkedList {
    public:
        Stack();                    // constructor
        ~Stack();                   // destructor
        void push(int value);       // add a value to top of stack
        int pop();                  // remove top value of stack
        int& top();                 // return reference to top value of stack
};

#endif
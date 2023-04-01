// author: Wendy Haw
// collaborators: none

#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#include "LinkedList_char.h"

// create Stack class and inherit public members from LinkedList class
class Stack : public LinkedList {
    public:
        Stack();                    // constructor
        ~Stack();                   // destructor
        void push(char value);      // add a value to top of stack
        char pop();                 // remove top value of stack
        char& top();                // return reference to top value of stack
};

#endif
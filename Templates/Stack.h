// author: Wendy Haw
// collaborators: none

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <string>

using namespace std;


// create Stack class and inherit public members from LinkedList class
template<class T>
class Stack : public LinkedList<T> {
    public:
        Stack();                    // constructor
        ~Stack();                   // destructor
        void push(T value);         // add a value to top of stack
        T pop();                    // remove top value of stack
        T& top();                   // return reference to top value of stack
};

// instantiate multiple data types for Stack class
template class Stack<int>;
template class Stack<float>;
template class Stack<bool>;
template class Stack<double>;
template class Stack<char>;
template class Stack<string>;

#endif
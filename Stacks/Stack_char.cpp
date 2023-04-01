// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList_char.h"
#include "Stack_char.h"

using namespace std;

// constructor
Stack::Stack(){

}

// destructor
Stack::~Stack(){

}

// use insertAtBack() inherited from LinkedList class 
void Stack::push(char value){
    LinkedList::insertAtBack(value);
}

// use getLast() inherited from LinkedList class
char& Stack::top(){
    return LinkedList::getLast()->val;
}

// use removeFromBack() inherited from LinkedList class
char Stack::pop(){
    // create char variable to store value that will be removed
    char pop_value = Stack::top();
    LinkedList::removeFromBack();
    return pop_value;
}


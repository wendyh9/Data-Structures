// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

// constructor
Stack::Stack(){

}

// destructor
Stack::~Stack(){

}

// use insertAtBack() inherited from LinkedList class
void Stack::push(int value){
    LinkedList::insertAtBack(value);
}

// use getLast() inherited from LinkedList class
int& Stack::top(){
    return LinkedList::getLast()->val;
}

// use removeFromBack() inherited from LinkedList class
int Stack::pop(){
    // create int variable to store value that will be removed
    int pop_value = Stack::top();
    LinkedList::removeFromBack();
    return pop_value;
}


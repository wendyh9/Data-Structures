// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList_char.h"
#include "Queue_char.h"

using namespace std;

// constructor
Queue::Queue(){

}

// destructor
Queue::~Queue(){

}

// inserts new element (value) at back of the Queue
void Queue::enqueue(char value){
    // use insertAtBack() inherited from LinkedList class
    LinkedList::insertAtBack(value);
}

// reference to front element of the Queue
char& Queue::front(){
    if (LinkedList::isEmpty()){
        throw 'A';
    }
    // use getFirst() inherited from LinkedList class
    return LinkedList::getFirst()->val;
}

// removes the first element of the Queue
char Queue::dequeue(){
    if (LinkedList::isEmpty()){
        throw 'A';
    }

    // create char variable to store value that will be removed
    char removed_val = Queue::front();
    // use removeFromFront() inherited from LinkedList class
    LinkedList::removeFromFront();
    return removed_val;
}


// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList.h"
#include "Queue.h"

using namespace std;

// constructor
Queue::Queue(){

}

// destructor
Queue::~Queue(){

}

// inserts new element (value) at back of the Queue
void Queue::enqueue(int value){
    // use insertAtBack() inherited from LinkedList class
    LinkedList::insertAtBack(value);
}

// reference to front element of the Queue
int& Queue::front(){
    if (LinkedList::isEmpty()){
        throw 1;
    }
    // use getFirst() inherited from LinkedList class
    return LinkedList::getFirst()->val;
}

// removes the first element of the Queue
int Queue::dequeue(){
    if (LinkedList::isEmpty()){
        throw 1;
    }

    // create int variable to store value that will be removed
    int removed_val = Queue::front();
    // use removeFromFront() inherited from LinkedList class
    LinkedList::removeFromFront();
    return removed_val;
}


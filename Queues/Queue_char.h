// author: Wendy Haw
// collaborators: none

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList_char.h"

using namespace std;

class Queue : public LinkedList{
    public:
        Queue(); // constructor
        ~Queue(); // destructor
        void enqueue(char value); // adds element to end of Queue
        char dequeue(); // remove last element and returns removed element
        char& front(); // returns reference to front element

};

#endif
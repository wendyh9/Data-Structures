// author: Wendy Haw
// collaborators: none

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

using namespace std;

class Queue : public LinkedList{
    public:
        Queue(); // constructor
        ~Queue(); //destructor
        void enqueue(int value); // adds element to end of Queue
        int dequeue(); // remove last element and returns removed element
        int& front(); // returns reference to front element

};

#endif
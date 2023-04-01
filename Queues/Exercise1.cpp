// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList.h"
#include "Queue.h"

using namespace std;

int main(){
    // create Queue object
    Queue line;

    // check if line is empty
    if (line.isEmpty()){
        cout << "line is empty!" << endl;
    }
    else{
        cout << "line is NOT empty..." << endl;
    }

    // put at least 10 elements in line
    line.enqueue(1); 
    line.enqueue(2);
    line.enqueue(3);
    line.enqueue(4);
    line.enqueue(5);
    line.enqueue(6);
    line.enqueue(7);
    line.enqueue(8);
    line.enqueue(9);
    line.enqueue(10);

    // check if line is empty
    if (line.isEmpty()){
        cout << "line is empty!" << endl;
    }
    else{
        cout << "line is NOT empty..." << endl;
    }

    // print out elements from line
    cout << "Here is the line contents: ";
    line.print();
    cout << endl;

    // print out front element from line
    try{
        int front_val = line.front();
        cout << "First element of line: " << front_val << endl;
    }
    catch(int val){
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    // remove elements of line
    try{
        int removed_val = line.dequeue();
        cout << "Removed element: " << removed_val << endl;
    }    
    catch(int val){
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;
    }
    try{
        int removed_val = line.dequeue();
        cout << "Removed element: " << removed_val << endl;
    }    
    catch(int val){
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;
    }

    // add new element to line
    line.enqueue(11);

    // print out elements from line
    cout << "Here is the line contents: ";
    line.print();
    cout << endl;

    // print out front element from line
    try{
        int front_val = line.front();
        cout << "First element of line: " << front_val << endl;
    }
    catch(int val){
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    // print size of line
    cout << "Size of line: " << line.size() << endl;

    // remove all elements of line
    line.clear();

    // print size of line
    cout << "Size of line: " << line.size() << endl;

    // test exception for dequeue()
    try{
        int removed_val = line.dequeue();
        cout << "Removed element: " << removed_val << endl;
    }    
    catch(int val){
        cout << "Call to dequeue() generated an exception, because the queue is empty" << endl;
    }

    // test exception for front()
    try{
        int front_val = line.front();
        cout << "First element of line: " << front_val << endl;
    }
    catch(int val){
        cout << "Call to front() generated an exception, because the queue is empty" << endl;
    }

    return 0;
}
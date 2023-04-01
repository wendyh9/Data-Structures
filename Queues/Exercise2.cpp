// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include "LinkedList_char.h"
#include "Queue_char.h"

using namespace std;

int main(){
    // create Queue object
    Queue line;

    cout << "Function call      Output      Front   Queue   Rear" << endl << endl;

    // remove element from line
    cout << "dequeue()          ";
    try{
        // attempt to use dequeue()
        line.dequeue();
    }
    // catch thrown val
    catch(char val){
        cout << "Call to dequeue() generated an exception, because the queue is empty";
    }
    line.print();
    cout << endl;

    // add 'D' to line
    cout << "enqueue(D)                     ";
    line.enqueue('D');
    line.print(); 
    cout << endl;

    // add 'A' to line
    cout << "enqueue(A)                     ";
    line.enqueue('A');
    line.print();
    cout << endl;

    // remove element from line
    cout << "dequeue()          ";
    try{
        // attempt to use dequeue()
        cout << line.dequeue();
    }
    // catch thrown value
    catch(char val){
        cout << "Call to dequeue() generated an exception, because the queue is empty";
    }
    cout << "           ";
    line.print();
    cout << endl;

    // print size of line
    cout << "size()             " << line.size() << "           ";
    line.print();
    cout << endl;

    // add 'D' to line
    cout << "enqueue(D)                     ";
    line.enqueue('D');
    line.print();
    cout << endl;

    // check if line is empty
    string result = (line.isEmpty()) ? "true":"false";
    cout << "isEmpty()          " << result << "       ";
    line.print();
    cout << endl;

    // print front element of line
    cout << "front()            ";
    try{
        // attempt to use front()
        char front_val = line.front();
        cout << front_val << "           ";
    }
    // catch thrown value
    catch(char val){
        cout << "Call to front() generated an exception, because the queue is empty";
    }
    line.print();
    cout << endl;

    // add 'T' to line
    cout << "enqueue(T)                     ";
    line.enqueue('T');
    line.print();
    cout << endl;

    // print front element of line
    cout << "front()            ";
    try{
        // attempt to use front()
        char front_val = line.front();
        cout << front_val << "           ";
    }
    // catch thrown value
    catch(char val){
        cout << "Call to front() generated an exception, because the queue is empty";
    }
    line.print();
    cout << endl;

    return 0;
}
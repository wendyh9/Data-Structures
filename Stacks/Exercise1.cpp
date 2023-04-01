// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

int main(){

    // create Stack object
    Stack stack_obj;

    // check if stack_obj is empty
    if(stack_obj.isEmpty())
        cout << "stack_obj is empty!" << endl;
    else
        cout << "stack_obj is NOT empty..." << endl; 

    // push at least 10 elements in stack_obj
    stack_obj.push(1);
    stack_obj.push(2);
    stack_obj.push(3);
    stack_obj.push(4);
    stack_obj.push(5);
    stack_obj.push(6);
    stack_obj.push(7);
    stack_obj.push(8);
    stack_obj.push(9);
    stack_obj.push(10);

    // print the size of stack_obj
    cout << "The size of stack_obj is: " << stack_obj.size() << endl;

    // print stack_obj contents
    cout << "Here is the stack_obj contents: "; stack_obj.print(); cout << endl;

    // check if stack_obj is empty
    if(stack_obj.isEmpty())
        cout << "stack_obj is empty!" << endl;
    else
        cout << "stack_obj is NOT empty..." << endl;   

    // remove top from stack_obj and print its value
    cout << "Removed: " << stack_obj.pop() << endl;

    // print stack_obj contents
    cout << "Here is the stack_obj contents: "; stack_obj.print(); cout << endl;

    // print top of stack_obj
    cout << "Here is the top: " << stack_obj.top(); cout << endl;

    // clear all elements from stack_obj
    stack_obj.clear();

    // check if stack_obj is empty
    if(stack_obj.isEmpty())
        cout << "stack_obj is empty!" << endl;
    else
        cout << "stack_obj is NOT empty..." << endl;   

    // print the size of stack_obj
    cout << "The size of stack_obj is: " << stack_obj.size() << endl;    

    return 0;
}
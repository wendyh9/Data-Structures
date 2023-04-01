// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include "LinkedList_char.h"
#include "Stack_char.h"

using namespace std;

int main(){

    cout << "Function call    Output      Stack Contents" << endl;
    cout << "                                           " << endl;

    // create stack object
    Stack stack_obj;
    
    // check is stack_obj is empty and store result in string
    string result =  (stack_obj.isEmpty()) ? "true": "false";
    cout << "isEmpty()        " << result << "     "; 
    stack_obj.print();
    cout << endl;

    // push char 'A' into stack_obj
    cout << "push(A)                      "; 
    stack_obj.push('A');
    stack_obj.print();
    cout << endl;

    // push char 'Y' into stack_obj
    cout << "push(Y)                      "; 
    stack_obj.push('Y');
    stack_obj.print();
    cout << endl;

    // print size of stack_obj
    cout << "size()           " << stack_obj.size() << "           ";
    stack_obj.print();
    cout << endl;

    // remove top of stack_obj and print what was removed
    cout << "pop()            " << stack_obj.pop() << "           ";
    stack_obj.print();
    cout << endl;

    // check is stack_obj is empty and store result in string
    result =  (stack_obj.isEmpty()) ? "true": "false";
    cout << "isEmpty()        " << result << "       ";
    stack_obj.print();
    cout << endl;

    // push char 'D' into stack_obj
    cout << "push(D)                      ";
    stack_obj.push('D');
    stack_obj.print();
    cout << endl;

    // remove top of stack_obj and print what was removed
    cout << "top()            " << stack_obj.top() << "           ";
    stack_obj.print();
    cout << endl;

    // push char 'T' into stack_obj
    cout << "push(T)                      ";
    stack_obj.push('T');
    stack_obj.print();
    cout << endl;

    // remove top of stack_obj and print what was removed
    cout << "pop()            " << stack_obj.pop() << "           ";
    stack_obj.print();
    cout << endl;

    return 0;
}
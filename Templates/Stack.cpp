// author: Wendy Haw
// collaborators: none

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Stack.h"

using namespace std;

// constructor
template <class T>
Stack<T>::Stack(){

}

// destructor
template <class T>
Stack<T>::~Stack(){

}

// use insertAtFront() inherited from LinkedList class
template <class T>
void Stack<T>::push(T value){
    LinkedList<T>::insertAtFront(value);
}

// use getLast() inherited from LinkedList class
template <class T>
T& Stack<T>::top(){
    return LinkedList<T>::getLast()->val;
}

// use removeFromBack() inherited from LinkedList class
template <class T>
T Stack<T>::pop(){
    // create int variable to store value that will be removed
    T pop_value = Stack<T>::top();
    LinkedList<T>::removeFromFront();
    return pop_value;
}


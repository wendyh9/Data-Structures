// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList.h"
using namespace std;

template<class T>
Node<T>::~Node(){

};

template<class T>
void Node<T>::operator=(const Node<T> &n){
    val = n.val;
    next = n.next;
}

// Constructor
template<class T>
LinkedList<T>::LinkedList(){
    first = NULL;
    last = NULL;
}

// Destructor
template<class T>
LinkedList<T>::~LinkedList(){

    // create nextNode to store node that is after node that will be deleted
    Node<T>* nextNode = NULL;

    // while first is not at end of list
    while(first != NULL){
        // store first's next node in nextNode
        nextNode = first->next;
        // delete first
        delete first;
        // set first to nextNode to advance in list
        first =  nextNode;  
    }
}

// returns Node pointer last
template <class T>
Node<T>* LinkedList<T>::getLast(){
    return last;
}

template<class T>
void LinkedList<T>::insertAtBack(T valueToInsert){

    Node<T>* n = new Node<T>;
    n->next = NULL;
    n->val = valueToInsert;

    // if there is a node prior to n
    if (first != NULL){
        last->next = n;
        last = last->next;
    }
    // if empty list
    else{
        first = n;
        last = n;
    }
}

template<class T>
bool LinkedList<T>::removeFromBack(){
    // if empty list
    if (first == NULL){
        return false;
    }

    // if list has only one node
    else if(first->next == NULL){
        delete first;
        first = NULL;
        return true;
    }

    // if list has more than one node
    else{
        Node<T>* beforeDel = first;
        while (beforeDel->next->next != NULL){
            beforeDel = beforeDel->next;
        }
        delete beforeDel->next;
        beforeDel->next = NULL;
        last = beforeDel;
        beforeDel = NULL;

        return true;
    }
}

template<class T>
void LinkedList<T>::print(){
    Node<T>* temp = first;

    while(temp != NULL){
        cout << temp->val;
        if (temp != last){
            cout << ",";
        }
        temp = temp->next;
    }
}

template<class T>
bool LinkedList<T>::isEmpty(){
    // check if first is NULL
    if (first == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
int LinkedList<T>::size(){
    // create int variable size
    int size = 0;
    // if first is NULL return size
    if (first == NULL){
        return size;
    }
 
    else{
        // create pointer to first called temp
        Node<T>* temp = first;
        // as long as temp is not NULL increment size and set temp as its next node
        while (temp != NULL){
            size += 1;
            temp = temp->next;
        }
        return size;
    }
    
}

template<class T>
void LinkedList<T>::clear(){
    // create nextNode to store node that is after node that will be deleted
    Node<T>* nextNode = NULL;

    // while first is not at end of list
    while(first != NULL){
        // store first's next node in nextNode
        nextNode = first->next;
        // delete first
        delete first;
        // set first to nextNode to advance in list
        first =  nextNode;
        
    }
}

template<class T>
void LinkedList<T>::insertAtFront(T valueToInsert){
    // create new node to insert at front
    Node<T>* n = new Node<T>;
    n->next = first;
    n->val = valueToInsert;

    first = n;

    // if there is only one node
    if (first->next == NULL){
        last = n;
    }

}

template<class T>
bool LinkedList<T>::removeFromFront(){
    // if list is empty
    if (first == NULL){
        return false;
    }

    // if list has only one node
    if (first->next == NULL){
        delete first;
        first = NULL;
        return true;
    }

    // if list has more than one node
    else{
        Node<T>* newFirst = first->next;
        delete first;
        first = newFirst;
        return true;
    }

}
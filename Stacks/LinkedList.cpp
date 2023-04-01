// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "LinkedList.h"

using namespace std;

Node::~Node(){

};

void Node::operator=(const Node &n){
    val = n.val;
    next = n.next;
}

// Constructor
LinkedList::LinkedList(){
    first = NULL;
    last = NULL;
}

// Destructor
LinkedList::~LinkedList(){

    // create nextNode to store node that is after node that will be deleted
    Node* nextNode = NULL;

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

bool LinkedList::isEmpty(){
    // check if first is NULL
    if (first == NULL){
        return true;
    }
    else{
        return false;
    }
}

// returns Node pointer last
Node* LinkedList::getLast(){
    return last;
}



void LinkedList::insertAtBack(int valueToInsert){

    Node* n = new Node;
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

bool LinkedList::removeFromBack(){
    // if empty list
    if (isEmpty()){
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
        Node* beforeDel = first;
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


void LinkedList::print(){
    Node* temp = first;
    // while temp is not at end of linked list
    while(temp != NULL){
        cout << temp->val;
        if (temp != last){
            cout << ", ";
        }
        temp = temp->next;
    }
}



int LinkedList::size(){
    // create int variable size
    int size = 0;
    // if first is NULL return size
    if (first == NULL){
        return size;
    }
 
    else{
        // create pointer to first called temp
        Node* temp = first;
        // as long as temp is not NULL increment size and set temp as its next node
        while (temp != NULL){
            size += 1;
            temp = temp->next;
        }
        return size;
    }
    
}
void LinkedList::clear(){
    // create nextNode to store node that is after node that will be deleted
    Node* nextNode = NULL;

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


void LinkedList::insertAtFront(int valueToInsert){
    // create new node to insert at front
    Node* n = new Node;
    n->next = first;
    n->val = valueToInsert;

    first = n;

    // if there is only one node
    if (first->next == NULL){
        last = n;
    }

}

bool LinkedList::removeFromFront(){
    // if list is empty
    if (isEmpty()){
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
        Node* newFirst = first->next;
        delete first;
        first = newFirst;
        return true;
    }

}
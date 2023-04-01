// author: Wendy Haw
// collaborator: none

#ifndef LINKEDLIST_CHAR_H
#define LINKEDLIST_CHAR_H

using namespace std;

// Representation of an element in the linked list
struct Node 
{
    char val; // Value of the node
    Node* next; // Pointer to the next node

    ~Node(); // Destructor
    void operator=(const Node &n); // overload assignment operator
};

class LinkedList 
{
    // Public Functions/Variables
    public:

        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(char valueToInsert); // adds a node in back
        bool removeFromBack(); // remove last node
        void print(); // print contents of linked list
        bool isEmpty(); // returns if linked list is empty
        int size(); // returns size of linked list
        void clear(); // removes all nodes from linked list


        void insertAtFront(char valueToInsert); // adds a node to front
        bool removeFromFront(); // removes first node

        Node* getLast(); // gets last pointer

    // Private Functions/Variables
    private:
        Node *first; // Pointer pointing to the begining of the list
        Node *last; // Pointer pointing to the end of the list
};


#endif
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std;


// Representation of an element in the linked list
template<class T>
struct Node
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
    ~Node();
    void operator=(const Node &n);
};

template<class T>
class LinkedList
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert);
        bool removeFromFront();

        Node<T>* getLast(); // gets last pointer

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};
// instantiate multiple data types for LinkedList class 
template class LinkedList<float>;
template class LinkedList<char>;
template class LinkedList<int>;
template class LinkedList<bool>;
template class LinkedList<double>;
template class LinkedList<string>;

#endif


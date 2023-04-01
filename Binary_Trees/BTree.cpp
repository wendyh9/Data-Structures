// author: Wendy Haw
// collaborators: none

#include <iostream>
#include "BTree.h"

// constructor
BTree::BTree(){
    root = NULL;
}

// destructor
BTree::~BTree(){
    BTree::destroy_tree();
}

// returns pointer to root of Binary Tree
Node* BTree::BTree_root(){
    return root;
}

void BTree::destroy_tree(Node* leaf){
    // check if binary tree is empty
    if (leaf == NULL){
        return;
    }
    // check if leaf exists in binary tree
    if (BTree::search(leaf->key_value) == NULL){
        return;
    }
    else{
        // delete left child
        BTree::destroy_tree(leaf->left);
        // delete right child
        BTree::destroy_tree(leaf->right);
        // remove leaf 
        delete leaf;
        // set leaf to NULL
        leaf = NULL;        
    }
}

void BTree::insert(int key, Node* leaf){
    // if key is smaller than key_value
    if (key < leaf->key_value){
        // check if leaf's left child is not NULL
        if (leaf->left != NULL){
            // recusively call the function for leaf's left child
            BTree::insert(key, leaf->left);
        }
        // if leaf's left child is NULL
        else{
            // create new Node
            leaf->left = new Node;
            // assign key_value to key 
            leaf->left->key_value = key;
            // set left child to NULL
            leaf->left->left = NULL;
            // set right child to NULL
            leaf->left->right = NULL;
        }
    }
    // if key is greater than or equal to key_value
    if (key > leaf->key_value || key == leaf->key_value){
        // check if leaf's right child is not NULL
        if (leaf->right != NULL){
            // recusively call the function for leaf's right child
            BTree::insert(key, leaf->right);
        }
        // if leaf's right child is NULL
        else{
            // create new Node
            leaf->right = new Node;
            // assign key_value to key 
            leaf->right->key_value = key;
            // set left child to NULL
            leaf->right->left = NULL;
            // set right child to NULL
            leaf->right->right = NULL;
        }
    }   
}

Node* BTree::search(int key, Node* leaf){
    // pre order traversal 
    // if binary tree is not empty   
    if (leaf != NULL){
        // leaf has been found
        if (key == leaf->key_value){
            return leaf;
        }
        // key is less than leaf's key-value
        if (key < leaf->key_value){
            return BTree::search(key, leaf->left);
        }
        // key is greater than leaf's key-value
        else{
            return BTree::search(key, leaf->right);
        }        
    }
    // empty binary tree
    else{
        return NULL;
    }

}

void BTree::insert(int key){
    // if binary tree is not empty
    if (root != NULL){
        BTree::insert(key, root);
    }
    // if binary tree is empty
    else{
        root = new Node;
        root->key_value = key;
        root->left = NULL;
        root->right = NULL;
    }

}

Node* BTree::search(int key){    
    // use search(key, Node* leaf)
    return BTree::search(key, root);

}

void BTree::destroy_tree(){
    // use destroy_tree(Node* leaf)
    BTree::destroy_tree(root);
    
}
#include "AVLTree.h"

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {

}


/**
  * Finds and returns the node with a given value
  *
  * @param value The value to find
  * @return Node* The node where the desired value is (or NULL if the value could not be found
  */
Node* AVLTree::findValue(int value) {

}


/**
  * Finds the max value in a tree with root 'n'
  *
  * @param n The node to start the search at
  * @return int The max value within the tree
  */
int AVLTree::findMax(Node* n) {

}


/**
  * Inserts a value into the tree
  *
  * @param value The value to insert
  */
void AVLTree::insertValue(int value) {
    // Insert value into this node
    if(root == NULL) {
        root = new Node(value);
    } else {
        root = insertValue(root, value);
    }
}


/**
  * Inserts a value into a tree with a given root
  *
  * @param n The node to insert the value at
  * @param value The value to insert
  */
Node* AVLTree::insertValue(int value, Node* n) {

    // Insert value at this node
    if(n == NULL) {
        n = new Node(value);
        return n;
    }


    // Insert value in left subtree
    if(value <= n.value) {
        insertValue()
    }
}


/**
  * Deletes a value from the tree. Only the first instance found will be deleted
  *
  * @param value The value to delete
  */
void AVLTree::deleteValue(int value) {

}

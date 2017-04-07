#include <algorithm>
#include <iostream>
#include <cstdio>
#include "AVLTree.h"

using namespace std;


/**
  * Default constructor
  */
AVLTree::AVLTree() {
    root = NULL;
}


/**
  * Destructor
  */
AVLTree::~AVLTree() {
    deleteTree(root);
}


void AVLTree::deleteTree(Node* n) {
    if(n != NULL) {
        deleteTree(n->left);
        deleteTree(n->right);
        delete n;
    }
}


/**
  * Inserts a value into the AVL Tree
  *
  * @param value The value to insert
  */
void AVLTree::insertValue(int value) {
    root = insertValue(root, value);
}


/**
  * Find the minimum value in the tree
  *
  * @return The minimum integer
  */
int AVLTree::findMin() {
    if(root == NULL) {
        return -1;
    }

    Node* n = root;
    int value = root->value;

    while(n != NULL) {
        value = n->value;
        n = n->left;
    }

    return value;
}


/**
  * Find the maximum value in the tree
  *
  * @return The maximum integer
  */
int AVLTree::findMax() {
    if(root == NULL) {
        return -1;
    }

    Node* n = root;
    int value = root->value;

    while(n != NULL) {
        value = n->value;
        n = n->right;
    }

    return value;
}


/**
  * Prints the AVL tree (in-order) in the terminal
  */
void AVLTree::printTree() {
    if(root != NULL) {
        printTree(root);
    }
}


/**
  * Prints the AVL tree (in-order)
  */
void AVLTree::printTree(Node* n) {
    if(n == NULL) {
        return;
    }

    printTree(n->left);
    cout << n->value << " ";
    printTree(n->right);
}


/**
  * Prints the tree as a physical tree structure
  */
void AVLTree::printStructure() {
    printStructure(root, 1);
}


/**
  * Prints the tree as a physical tree structure
  */
void AVLTree::printStructure(Node* n, int level) {
    if(n != NULL) {
        printStructure(n->right, level + 1);
        cout << "\n";

        if(n == root) {
            cout << "root -> ";
        }
        for(int i = 0; i < level && n != root; i++) {
            cout << "        ";
        }

        cout << n->value;
        printStructure(n->left, level + 1);

    }
}


/**
  * Inserts a value into the AVL Tree, starting at a given node
  *
  * @param n The node to insert the value into
  * @param value The value to insert
  * @return A Node object where the value was inserted
  */
Node* AVLTree::insertValue(Node* n, int value) {
    if(n == NULL) {
        return new Node(value);
    } else if(value < n->value) {
        n->left = insertValue(n->left, value);
        n = balance(n);
    } else if(value >= n->value) {
        n->right = insertValue(n->right, value);
        n = balance(n);
    }

    return n;
}


/**
  * Rotates the tree to fix height imbalance
  *
  * @param n The node to rotate on
  * @return A node object that was rotated
  */
Node* AVLTree::rotateRR(Node* n) {
    Node* temp;
    temp = n->right;
    n->right = temp->left;
    temp->left = n;

    return temp;
}


/**
  * Rotates the tree to fix height imbalance
  *
  * @param n The node to rotate on
  * @return A node object that was rotated
  */
Node* AVLTree::rotateLL(Node* n) {
    Node* temp;
    temp = n->left;
    n->left = temp->right;
    temp->right = n;

    return temp;
}


/**
  * Rotates the tree to fix height imbalance
  *
  * @param n The node to rotate on
  * @return A node object that was rotated
  */
Node* AVLTree::rotateLR(Node* n) {
    Node* temp;
    temp = n->left;
    n->left = rotateRR(temp);

    return rotateLL(n);
}


/**
  * Rotates the tree to fix height imbalance
  *
  * @param n The node to rotate on
  * @return A node object that was rotated
  */
Node* AVLTree::rotateRL(Node* n) {
    Node* temp;
    temp = n->right;
    n->right = rotateLL(temp);

    return rotateRR(n);
}


/**
  * Balances the left and right subtrees of a given node to fix height imbalance
  *
  * @param n The node to balance
  * @return A node object that was balanced
  */
Node* AVLTree::balance(Node* n) {
    int difference = getHeightDifference(n);

    if(difference > 1) {
        if(getHeightDifference(n->left) > 0) {
            n = rotateLL(n);
        } else {
            n = rotateLR(n);
        }
    } else if(difference < -1) {
        if(getHeightDifference(n->right) > 0) {
            n = rotateRL(n);
        } else {
            n = rotateRR(n);
        }
    }

    return n;
}


/**
  * Calculates the height difference between the left and right subtrees of a given node
  *
  * @param n The node to check
  * @return An integer showing the difference between the left and right subtrees
  */
int AVLTree::getHeightDifference(Node* n) {
    int lHeight = getHeight(n->left);
    int rHeight = getHeight(n->right);
    int difference = lHeight - rHeight;

    return difference;
}


/**
  * Calculates the height of a given node
  *
  * @param n The node to calculate the height of
  * @return An integer representing the height of the node
  */
int AVLTree::getHeight(Node* n) {
    int height = 0;

    if(n != NULL) {
        int lHeight = getHeight(n->left);
        int rHeight = getHeight(n->right);
        height = max(lHeight, rHeight) + 1;
    }

    return height;
}

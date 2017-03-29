#ifndef AVLTREE_H
#define AVLTREE_H

#include <cstddef> // For NULL


struct Node {
    Node* left = NULL;
    Node* right = NULL;
    int value = 0;

    Node(int _value) {
        value = _value;
    }
};


class AVLTree {
    public:
        AVLTree();
        virtual ~AVLTree();
        void insertValue(int value);
        void printTree();

    private:
        Node* root;

        Node* insertValue(Node* n, int value);
        Node* rotateRR(Node* n);
        Node* rotateLL(Node* n);
        Node* rotateLR(Node* n);
        Node* rotateRL(Node* n);
        Node* balance(Node* n);
        int getHeightDifference(Node* n);
        int getHeight(Node* n);
};

#endif // AVLTREE_H

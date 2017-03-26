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

        Node* findValue(int value);
        int findMax(Node* n);
        void insertValue(int value);
        void deleteValue(int value);

    private:
        Node* root;

        Node* insertValue(int value);
        Node* insertValue(int value, Node* n);
};

#endif // AVLTREE_H

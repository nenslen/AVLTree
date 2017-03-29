#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree* t = new AVLTree();

    t->insertValue(4);
    t->insertValue(7);
    t->insertValue(3);
    t->printTree();

    delete t;

    return 0;
}

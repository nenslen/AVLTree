#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree* t = new AVLTree();

    /*
    t->insertValue(10);
    t->insertValue(8);
    t->insertValue(12);
    t->insertValue(6);
    t->insertValue(9);
    t->insertValue(11);
    t->insertValue(15);
    */

    for(int i = 1; i <= 6; i++) {
        t->insertValue(i);
    }


    t->printTree();
    t->printStructure();

    delete t;
    return 0;
}

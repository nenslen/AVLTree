#include <iostream>
#include "AVLTree.h"
#include <chrono>
#include <fstream>
#include <math.h>


using namespace std;

int main()
{


    int time1 = 0;
    int time2 = 0;
    ofstream afile;
    afile.open("tests.txt");

    /*
    t->insertValue(10);
    t->insertValue(8);
    t->insertValue(12);
    t->insertValue(6);
    t->insertValue(9);
    t->insertValue(11);
    t->insertValue(15);
    */


    for(int i = 1; i <= 4; i++) {
        for(int j = 1; j < 10; j++) {
            AVLTree t;
            time1 = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
            for(int k = 1; k < pow(10, i) * (j); k++) {
                t.insertValue(i);
            }
            time2 = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
            afile << pow(10, i) * (j) << "\t" << time2 - time1 << "\n";
        }
    }

    for(int i = 0; i < 5000; i++) {
        //t->insertValue(i);
    }

    //t->printTree();
    //t->printStructure();
    afile.close();
    //delete t;
    return 0;
}

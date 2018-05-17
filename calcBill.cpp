#include "tree.h"

double calcBill(TREENODE* root){
    int counter = root->user.sentCount;
    double value;
    value =  (counter*0.2) - 0.6;
    if (value <= 0){ value = 0.0;}
    root->user.sentCount = 0;
    return value;
}



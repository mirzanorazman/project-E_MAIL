#include "tree.h"
#include <sstream>
void TraverseInOrder(TREENODE *root)
{
    std::ostringstream oss;
    if(!root) return;
    double dummy;
    TraverseInOrder(root->left);
    dummy = calcBill(root);
    oss << "User: " << root->user.name << "\n" << "Charge: " << dummy << " dollars\n";
    
    TraverseInOrder(root->right);
    std::cout << oss.str() << std::endl;
    billSummary += oss.str();
}

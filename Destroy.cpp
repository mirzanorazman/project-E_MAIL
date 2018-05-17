// Author : Mirza Nor Azman

#include "tree.h"
void Destroy(TREENODE *root)
{
    // Base case 0: the tree is empty –– do nothing;
    if (root) { // Recursive case:
        Destroy(root->left);
        Destroy(root->right);
        delete root;
    }
}

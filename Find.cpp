// Author : Mirza Nor Azman

#include "tree.h"

TREENODE *Find(TREENODE *root, const Subscriber user)
// *** Iterative version ***
{
    while (root) {
        int comp = Compare(user, root->user);
        if (comp == 0)
            break; // element found
        if (comp < 0)
            root = root->left;
        else // if (comp > 0)
            root = root->right;
    }
    return root;
}

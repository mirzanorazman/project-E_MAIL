// Author : Mirza Nor Azman

#include "tree.h"

bool Insert(TREENODE* &root, Subscriber user)
{
    if (!root) { // Base case 0: the tree is empty.
        // Allocate a new node and set the root
        // equal to the new node:
        TREENODE *newnode = new TREENODE;
        if (!newnode) return false;
        newnode->user = user;
        newnode->left =
        newnode->right = 0;
        root = newnode;
        return true;
    }
    int comp = Compare(user, root->user);
    if (comp == 0) // Base case: the element is already in the tree.
        return true; // Another version might report an error.
    else if (comp < 0) // Recursive case: insert
        return Insert(root->left, user); // into the left subtree.
    else // if (comp > 0) // Recursive case: insert
        return Insert(root->right, user); // into the right
    // subtree.
}

// Author : Mirza Nor Azman

#include "tree.h"

bool Remove(TREENODE* &root, const Subscriber user){
    // Removes the node whose data element is equal to data.
    // Returns OK if successful, FAILED if cannot
    // find the node.
        if (!root) // Base case 0: the tree is empty.
            return false;
        int comp = Compare(user, root->user);
        if (comp == 0) { // Base case:
            TREENODE *oldroot = root;
            if (root->left == 0) // No left child
                root = root->right;
            else if (root->right == 0) // No right child
                root = root->left;
            if (oldroot != root) { // If one of the above...
                delete oldroot;
                return true;
            }
            TREENODE *parent = root;
            TREENODE *next = root->right;
            while (next->left) {
                parent = next;
                next = next->left;
            }
            if (parent == root)
                root->right = next->right;
            else
                parent->left = next->right;
            // Make this element the new root
            next->left = root->left;
            next->right = root->right;
            delete root;
            root = next;
            return true;
        }
        else if (comp < 0) // Recursive case: remove
            return Remove(root->left, user); // from the left subtree
        else // if (comp > 0) // Recursive case: remove
            return Remove(root->right, user); // from the right subtree
}

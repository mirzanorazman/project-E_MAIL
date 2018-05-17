#ifndef tree_h
#define tree_h

#include "email.h"

struct TREENODE {
    Subscriber user;
    TREENODE *left;
    TREENODE *right;
};
TREENODE *LoadTree (char filename[]);
extern void SaveTree (char filename[], TREENODE *root);
void Destroy(TREENODE *root);
TREENODE *Find(TREENODE *root, const Subscriber user);
bool Insert(TREENODE* &root, const Subscriber user);
bool Remove(TREENODE* &root, const Subscriber user);
void TraverseInOrder(TREENODE *root);
extern double calcBill(TREENODE* root);
extern int Compare(const Subscriber user1, const Subscriber user2);
extern void Copy(const Subscriber user1, Subscriber user2);
extern TREENODE *root;
extern TREENODE* subPtr;
extern std::string billSummary;
#endif /* tree_h */

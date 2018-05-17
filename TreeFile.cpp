// Author : Mirza Nor Azman

// TREEFILE.CPP
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "tree.h"
using namespace std;
static void RecursiveSave (ofstream &outp, TREENODE *root);
static TREENODE *RecursiveLoad (ifstream &inp);

streampos oldpos;

void SaveTree (char filename[], TREENODE *root)
// Opens a file for writing and saves the tree in it.
{
    ofstream outp(filename);
    if (!outp) {
        cerr << "Cannot create " << filename << endl;
        return;
    }
    RecursiveSave(outp, root);
}

TREENODE *LoadTree (char filename[])
// Opens a file for reading and loads the tree from it.
// If the file does not exist, returns null.
{
    ifstream inp(filename);
    if (!inp) return 0;
    return RecursiveLoad(inp);
}

static void RecursiveSave (ofstream &outp, TREENODE *root)
// Recursive utility function -- called from SaveTree;
// Assumes that outp is open for writing.
{
    outp << "[";
    if (root) {
        outp << endl;
        outp << root->user.name << endl;
        outp << root->user.password << endl;
        outp << root->user.sentCount << endl;
        while(root->user.mailbox.returnUnread()>0){
            Message get;
            root->user.mailbox.removeQ(get);
            outp << get.from << endl;
            outp << get.to << endl;
            outp << get.text << endl;
        }
        RecursiveSave (outp, root->left);
        RecursiveSave (outp, root->right);
    }
    outp << "]\n"; // An empty tree is saved as one line: []
}

static TREENODE *RecursiveLoad (ifstream &inp)
// Recursive utility function –– called from LoadTree
{
    char buf[80];
    inp.seekg(oldpos);
    inp.getline(buf, 80);
        //if (buf[0] == '[') break; // first '['.
    if (buf[1] == ']'){
        oldpos = inp.tellg();
        return 0;
    }// If the tree is empty...
    
//    if(buf[0] == ']')
//        return 0;
    
    TREENODE *root = new TREENODE;
    inp.getline(buf, 80);// Read the next line into buf
        oldpos = inp.tellg();
    root->user.name = buf;// Set node–>data from buf
    inp.getline(buf,80);
        oldpos = inp.tellg();
    root->user.password = buf;
    inp.getline(buf, 80);
    oldpos = inp.tellg();
    root->user.sentCount = atoi(buf);
    
    inp.getline(buf, 80);
        //oldpos = inp.tellg();
    char openBrac = '[';
    char closedBrac = ']';
    

    while(buf[0] != openBrac || buf[0] == closedBrac){
        Message put;
        put.from = buf;
        inp.getline(buf, 80);
        put.to = buf;
        inp.getline(buf,80);
        put.text = buf;
        oldpos = inp.tellg();
        root->user.mailbox.insertQ(put);
        inp.getline(buf, 80);
    }
    root->left = RecursiveLoad(inp);
    root->right = RecursiveLoad(inp);
    inp.getline(buf, 80);// Read the closing ']'
    oldpos = inp.tellg();
    if (buf[0] != ']')
        cerr << "Tree file format error: " << buf << endl;
    return root;
}

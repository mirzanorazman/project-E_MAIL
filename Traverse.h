// Author : Mirza Nor Azman

typedef void CALLBACK(TREENODE *node) { 
    double value;
    value = (x*0.2) - 0.6;
    if(value <= 0) {value = 0;}
    cout << value;
    cout << node-> data << ' ';
}
Class Traversal{
    private:
        TREENODE *root;
        void RecursiveTraverseInOrder(TREENODE* node, CALLBACK Visit);
        void Destroy(TREENODE *node);
    public:
        TREE() { root = 0;}
        void TraverseInOrder(CALLBACK Visit){
            RecursiveTraverseInOrder(root, Visit);}
        ~TREE(){Destroy(root);}
};

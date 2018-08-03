//function taking the root which checks if the given tree is a binary search tree or not

#include <climits>
bool checkNode(Node* n,int min,int max)
{
    if (!n) return true; //leaf, don't disqualify
    if (n->data < min || n->data > max) return false;
    return checkNode(n->left,min,n->data -1) && checkNode(n->right,n->data+1,max);
}

bool checkBST(Node* root) {return checkNode(root,INT_MIN,INT_MAX);}

// To find the lowest common ancestor of a binary serach tree


node * lca(node * root, int v1, int v2) {
    if (root == NULL || root->data == v1 || root->data == v2)
        return root;
    node * left = lca(root->left, v1, v2);
    node * right = lca(root->right, v1, v2);
    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    return right;
}

bool isbst(BinaryTreeNode<int>*root, int min, int max){
    if(root==NULL)return true;
    if(root->data>=min && root->data<=max){
        bool leftans = isbst(root->left, INT_MIN, root->data);
        bool rightans = isbst(root->right, root->data, INT_MAX);
        return leftans&&rightans;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    bool ans = isbst(root, INT_MIN, INT_MAX);
    return ans;
}
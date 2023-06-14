int solve(BinaryTreeNode<int>*Node,int &i, int k ){
    if(Node==NULL)return -1;
    int leftans = solve(Node->left,i,k);
    if(leftans!=-1){
        return leftans;
    }
    i++;
    if(i==k){
        return Node->data;
    }
    return solve(Node->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i =0;
    int ans= solve(root, i,k);
    return ans;
}
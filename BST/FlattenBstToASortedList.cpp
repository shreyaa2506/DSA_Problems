void inorder(TreeNode<int>* root, vector<int>&in){
    if (root == NULL){
        return ;
        
    }
    
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root ->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>inorderval;
    inorder(root,inorderval);
    
    TreeNode<int>*newroot = new TreeNode<int>(inorderval[0]);
    TreeNode<int>*curr = newroot;
    
    for(int i =1; i<inorderval.size(); i++){
        TreeNode<int> * temp = new TreeNode<int>(inorderval[i]);
        curr->left=NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left=NULL;
    curr->right =NULL;
    return newroot;
        
}

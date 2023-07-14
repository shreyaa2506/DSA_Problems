void func(TreeNode*root, int curr){
    if(root==NULL)return ;
    if(root->val>=curr){
        curr= root->val;
        ans++;
    }
    func(root->left,curr);
    func(root->right,curr);
}
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        func(root,root->val);
        return ans;
    }
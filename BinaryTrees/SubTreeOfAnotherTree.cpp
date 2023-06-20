bool ans = false;
bool match(TreeNode*r1, TreeNode*r2){
       if(r1==NULL && r2==NULL)return true;
        if(r1==NULL && r2!=NULL)return false;
        if(r1!=NULL && r2==NULL)return false;
        bool left = match(r1->left , r2->left);
        bool right = match(r1->right, r2->right);
        bool value = r1->val == r2->val;
        if(left && right && value)return true;
        return false;
        
}
    void inorder(TreeNode*root, TreeNode*subRoot){
        if(root!=NULL){
            
            inorder(root->left, subRoot);
            bool x = match(root,subRoot);
            if(x)ans=true;
            inorder(root->right,subRoot);
            
            
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorder(root,subRoot);
        return ans;

    }
TreeNode* invertTree(TreeNode* root) {
         if (root == NULL) {
        return NULL;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        
        TreeNode* temp = front->left;
        front->left = front->right;
        front->right = temp;
        
        if (front->left) {
            q.push(front->left);
        }
        if (front->right) {
            q.push(front->right);
        }
    }
    
    return root;
}
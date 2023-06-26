int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long ans = 0;
        while(!q.empty()){
            int n = q.size();
            long start = q.front().second;
            long end = q.back().second;
            ans = max(ans, end-start+1);
            
            for(int i =0 ; i<n;i++){
                TreeNode*node= q.front().first;
                long idx = q.front().second;
                q.pop();
                if(node->left)q.push({node->left, 2*idx+1});
                if(node->right)q.push({node->right,2*idx+2});
            }
        }
        return ans;
    }
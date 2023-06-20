 int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int ans = 0;
        int maxsum =INT_MIN;
        while(!q.empty()){
           
            int sz = q.size();
            int sum=0;
            level++;
            
            while(sz--){
                TreeNode*frontNode = q.front();
                q.pop();
                
                if(frontNode)sum+=frontNode->val;
                
                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);
            
            }
            if(sum>maxsum){
                    maxsum = sum;
                    ans = level;}
        }
        return ans;
    }
long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>arr;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int ans = 0;
        long long maxsum =0;
        
        while(!q.empty()){
           
            int sz = q.size();
            long long sum=0;
            level++;
            
            while(sz--){
                TreeNode*frontNode = q.front();
                q.pop();
                
                if(frontNode) sum+=frontNode->val;
                
                if(frontNode->left)q.push(frontNode->left);
                if(frontNode->right)q.push(frontNode->right);
            
            }
            arr.push_back(sum);
        }
        if(level<k)return -1;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        if(arr[n-k])return arr[n-k];
        else return -1;

    }
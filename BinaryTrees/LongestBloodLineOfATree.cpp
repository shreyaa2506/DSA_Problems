void solve(Node*root, int len, int sum, int &maxsum, int &maxlen){
        if(root==NULL){
            if(len>maxlen){
                maxlen = len;
                maxsum = sum;
                
            }
            else if(len == maxlen){
                maxsum= max(sum,maxsum);
            }
            return;
        }
        sum = sum +root->data;
        solve(root->left, len+1, sum,maxsum,maxlen);
        solve(root->right,len+1,sum,maxsum,maxlen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len,maxsum,sum,maxlen=0;
        solve(root,len,sum,maxsum,maxlen);
        return maxsum;
    }
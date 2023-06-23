void solve(Node*node , vector<int>&v){
        if(node==NULL)return;
        solve(node->left,v);
        v.push_back(node->data);
        solve(node->right,v);
    }
    int kthLargest(Node *root, int K)
    {
        vector<int>v;
        solve(root,v);
        if(v.size()<1)return -1;
        return v[v.size()-K];
    }
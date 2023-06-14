vector<int> reverseLevelOrder(Node *root)
{
       // code here
    vector<int>ans;
    if(root==NULL)
        return ans;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr= q.front();
        q.pop();
        ans.push_back(curr->data);
        if(curr->right) q.push(curr->right);
        if(curr->left) q.push(curr->left);
    }
    reverse(ans.begin(),ans.end());
    return ans;
   
}
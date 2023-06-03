//https://practice.geeksforgeeks.org/problems/sum-tree/1
pair<bool,int>isSumTreeFast(Node*root){
        if(root==NULL){
            pair<bool,int>p={true,0};
            return p;
        }
        if(root->left==NULL && root->right == NULL){
            pair<bool,int>p = {true,root->data};
            return p;
        }
        
        pair<bool,int>leftans = isSumTreeFast(root->left);
        pair<bool,int>rightans = isSumTreeFast(root->right);
        
        bool isleftsumtree= leftans.first;
        bool isrightsumtree= rightans.first;
        
        int leftsum = leftans.second;
        int rightsum = rightans.second;
        int cond = root->data == leftsum+rightsum;
        pair<bool,int>ans;
        ans.second = 2*(root->data);
        if(isleftsumtree&& isrightsumtree && cond){
            ans.first = true;
        }
        else ans.first = false;
        return ans;
    }
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
    }
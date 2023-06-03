//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

O(n^2)solution
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(struct Node* node){
         if(node==NULL){
             return 0;
         }
         int left = height(node->left);
         int right = height(node->right);
         int ans = max(left,right)+1;
         return ans;
       
    }
    
    bool isBalanced(Node *root)
    {
        if(root==NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height (root->left)-height(root->right))<=1;
        if(left&&right&&diff){
            return true;
        }else{
            return false;
        }
    }
};


O(n) solution
pair<bool,int>isBalancedFast(Node *root){
       if(root==NULL){
           pair<bool,int>p={true,0};
           return p;
       }
       pair<bool,int>left = isBalancedFast(root->left);
       pair<bool,int>right = isBalancedFast(root->right);
       
       bool leftAns = left.first;
       bool RightAns = right.first;
       bool diff = abs(left.second-right.second)<=1;
       pair<bool,int>ans;
       ans.second = max(left.second,right.second)+1;
       if(leftAns && RightAns && diff){
           ans.first = true;
       }
       else{
           ans.first = false;
       }
       return ans;
    }
    bool isBalanced(Node *root)
    {
        return isBalancedFast(root).first;
    }

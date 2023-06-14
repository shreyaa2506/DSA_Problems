class Solution {
     int minDiff = INT_MAX;
    int prevVal = INT_MAX;

    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        
        inorderTraversal(node->left);
        
        if (prevVal != INT_MAX) {
            minDiff = min(minDiff, abs(node->val - prevVal));
        }
        
        prevVal = node->val;
        
        inorderTraversal(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDiff;
    }
};
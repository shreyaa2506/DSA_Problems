class Solution {
public:

    int findpos(vector<int>inorder, int ele, int n){
        for(int i =0; i<n;i++){
            if(inorder[i]==ele)return i;
            
        }
        return -1;
    }

    TreeNode*solve(vector<int>preorder, vector<int>inorder, int &index, int instart, int inend, int n){
        if(index>=n || instart>inend){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode*root = new TreeNode(element);
        int pos = findpos (inorder, element,n);
        root->left = solve(preorder,inorder,index, instart,pos-1, n);
        root->right = solve(preorder,inorder,index,pos+1, inend,n);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex = 0;
        int n = inorder.size();
        TreeNode*ans = solve(preorder,inorder, preorderindex,0,n-1,n);
        return ans;
    }
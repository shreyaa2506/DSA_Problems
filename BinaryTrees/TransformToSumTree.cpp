 //https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
 int tosum(Node*node){
        if(node==NULL){
            return 0;
        }
        int leftans = tosum(node->left);
        int rightans = tosum(node->right);
        int x = node->data;
        
        node->data = leftans+rightans;
        return x+leftans+rightans;
    }
    void toSumTree(Node *node)
    {
       tosum(node);
        
    }
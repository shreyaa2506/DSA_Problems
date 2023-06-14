Node*solve(Node*root, int &k, int node){
    if(root==NULL)return NULL;
    if(root->data==node)return root;
    Node* lans = solve(root->left, k, node);
    Node* rans = solve(root->right,k,node);
    if(lans!=NULL && rans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        else{
            return lans;
        }
    }
    if(rans!=NULL && lans==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        else{
            return rans;
        }
    }
    else{
        return NULL;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    
    Node*ans = solve(root, k, node);
    if(ans==NULL || ans->data==node){
        return -1;
    }
    else{
        return ans->data;
    }
}

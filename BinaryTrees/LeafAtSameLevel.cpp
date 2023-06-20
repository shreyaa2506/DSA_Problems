int maxi (Node*root){
        if(root==NULL)return 0;
        int l = maxi(root->left);
        int r = maxi (root->right);
        return max(l,r)+1;
    }
    int mini(Node*root){
        if (root==NULL)return 0;
        int l = mini(root->left);
        int r = mini(root->right);
        if(l==0 || r==0 ){
            return l+r+1;
        }
        else{
            return min(l,r)+1;
        }
    }
    bool check(Node *root)
    {
       if(maxi(root)==mini(root)){
           return true;
       }else{
           return false;
       }
    }   
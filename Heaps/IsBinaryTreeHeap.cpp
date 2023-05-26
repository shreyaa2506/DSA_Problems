int countNodes(Node*root){
      if(root==NULL){
          return 0;
      }
      int ans=1+countNodes(root->left)+countNodes(root->right);
      return ans;
  }
  
  bool isCBT(Node*root, int i, int cnt){
      if(root==NULL){
          return true;
      }
      if(i>=cnt){
          return false;
      }
      else{
          bool left = isCBT(root->left, 2*i+1,cnt);
          bool right = isCBT(root->right , 2*i+2,cnt);
          return (left && right);
      }
      
  }
  
  bool Maxorder(Node*root){
      if(root->left ==NULL && root->right ==NULL){
          return true;
      }
      if(root->right == NULL){
          return (root->data>root->left->data);
      }
      else{
          bool left = Maxorder(root->left);
          bool right = Maxorder(root->right);
          return (left&&right&&(root->data>root->left->data && root->data>root->right->data));
      }
  }
    
    bool isHeap(struct Node* tree) {
        int i =0;
        if(tree==NULL){
            return true;
        }
        if(isCBT(tree,i,countNodes(tree))&& Maxorder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
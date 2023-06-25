  Node*preorder(int pre[], int &i,int bound,int n){
      if(i==n||pre[i]>bound)return NULL;
      Node*root = newNode(pre[i++]);
      
      root->left = preorder(pre,i,root->data,n);
      root->right = preorder(pre,i,bound,n);
      return root;
    }

    Node* post_order(int pre[], int size)
    {
        int i =0;
        return preorder(pre,i,INT_MAX,size);
    }
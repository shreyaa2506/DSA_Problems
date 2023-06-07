 vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>result;
    	if(root==NULL){
    	    return result;
    	}
    	bool lefttoright = true;
    	queue<Node*>q;
    	q.push(root);
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int>ans(size);
    	    for(int i =0; i<size;i++){
    	        Node*front = q.front();
    	        q.pop();
    	        int index =  lefttoright?i:size-i-1;
    	        ans[index]=front->data;
    	        if(front->left){
    	            q.push(front->left);
    	        }
    	        if(front->right){
    	            q.push(front->right);
    	        }
    	        
    	    }
    	    for(auto i:ans){
    	        result.push_back(i);
    	    }
    	    lefttoright=!lefttoright;
    	}
    	return result;
    }
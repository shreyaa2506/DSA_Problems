int kthSmallest(int arr[], int l, int r, int k) {
        
        priority_queue<int>pq;
        for(int i =l;i<k;i++){
            pq.push(arr[i]);
            
        }
        
        for(int i =k;i<=r;i++){
            if(arr[i]<pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
        // priority_queue<int,vector<int>,greater<int>>minheap;
        // for(int i =l; i<=r;i++){
        //     minheap.push(arr[i]);
        // }
        // int size1 = minheap.size();
        // int size2= minheap.size();
        // while(size1>size2-k+1){
        //     minheap.pop();
        //     size1--;
        // }
        // return minheap.top();
    }
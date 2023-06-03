vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int>pq;
        vector<int>ans;
        for(int i =0; i<n;i++){
            pq.push(arr[i]);
        }
        int i=0;
        while(i<k){
            ans.push_back(pq.top());
            pq.pop();
            i++;
        }
        
	
	return ans;
	}

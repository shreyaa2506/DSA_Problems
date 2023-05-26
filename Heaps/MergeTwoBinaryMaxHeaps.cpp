void heapify(vector<int>&arr,int n, int i ){
   int largest = i;
   int left = 2*i+1;
   int right = 2*i+2;

   if(left<n && arr[left]>arr[largest]){
    largest = left;
   }
   if(right<n&& arr[right]>arr[largest]){
    largest = right;
   }
   if(largest!=i){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
   }

    
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>c;
        for(int i=0; i<a.size();i++){
            c.push_back(a[i]);
        }
        for(int i=0; i<b.size();i++){
            c.push_back(b[i]);
        }
        int size1 = c.size();
        for(int i=size1-1;i>=0;i--){
            heapify(c,size1,i);
        }
        return c;
        
        
    }
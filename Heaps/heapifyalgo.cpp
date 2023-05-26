void heapify(int arr[],int n, int i ){
   int largest = i;
   int left = 2*i;
   int right = 2*i+1;

   if(left<=n && arr[left]>arr[largest]){
    largest = left;
   }
   if(right<=n&& arr[right]>arr[largest]){
    largest = right;
   }
   if(largest!=i){
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);
   }

    
}

void main(int arr[],int n){
    for (int i =n/2 ;i>0;i--){
        heapify(arr,n,i);
    }
}
bool findPair(int arr[], int size, int n){
    
    sort(arr,arr+size);
    int i =0;
    int j =1;
    while(i<size && j<size){
        int x = arr[i];
        int y = arr[j];
        int diff = abs(y-x);
        if (diff == n){
            return true;
        }
        if (diff <n){
            j++;
        }
        else{
            i++;
        }
        if(i==j){
            j++;
        }
    }
    return 0;

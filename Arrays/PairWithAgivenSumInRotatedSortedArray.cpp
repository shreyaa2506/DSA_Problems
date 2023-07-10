bool pairInSortedRotated(int arr[], int n, int x){
    for(int i =0 ; i<n;i++){
        if(arr[i]>arr[i+1]){
            break;
        }
    }
    int l = (i+1)%n;
    int r = i;
    while(l!=r){
        if(arr[l]+arr[r]==x)return true;
        if(arr[l]+arr[r]<x) l = (l+1)%n;
        else r=(r+n-1)%n;
    }
    return false;
}
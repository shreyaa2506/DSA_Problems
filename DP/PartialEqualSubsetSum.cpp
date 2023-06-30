bool subsetSumToK(int n, int k, int arr[]) {
    int dp[n][k+1]={0};
    int prev[k+1]={0};
    int cur[k+1]={0};
    prev[0]= cur[0]=true;
    prev[arr[0]]= true;
    for(int ind =1 ; ind<n;ind++){
        for(int target = 1; target<=k;target++){
            bool nottake = prev[target];
            bool take = false;
            if(arr[ind]<=target)take = prev[target-arr[ind]];
            cur[target]= take| nottake;
        }
        memcpy(prev, cur, sizeof(cur)); 
        
    }
    return prev[k];

  
}
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i =0 ; i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0)return false;
        bool ans = subsetSumToK(n,sum/2,arr);
        if(ans==true)return 1;
        else return 0;
    }
 //memoixzation and tabulaiton
 
 int rec (int arr[], int idx,int n,vector<int>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
        int take = arr[idx]+ rec(arr,idx+2,n,dp);
        int nottake = rec(arr,idx+1,n,dp);
        return dp[idx]= max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int>dp(n+1,0);
        
        dp[0] = 0;
        dp[1] = arr[0];

    
    for (int i = 2; i <= n; i++)
    {
        int take = arr[i - 1] + dp[i - 2];
        int nottake = dp[i - 1];
        dp[i] = max(take, nottake);
    }

    return dp[n];
    }
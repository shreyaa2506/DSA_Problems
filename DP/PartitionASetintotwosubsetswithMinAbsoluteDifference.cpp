#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totsum=0;
	for(int i =0; i<n;i++){
		totsum+=arr[i];
	}
	int k = totsum;
	vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i =0 ; i<n;i++)dp[i][0]= true;
    if(arr[0]<=k)dp[0][arr[0]]= true;
    for(int ind =1 ; ind<n;ind++){
        for(int target = 1; target<=k;target++){
            bool nottake = dp[ind-1][target];
            bool take = false;
            if(arr[ind]<=target)take = dp[ind-1][target-arr[ind]];
            dp[ind][target]= take| nottake;
        }
    }
	int mini = 1e9;
    for(int j =0 ; j<=totsum/2;j++){
		if(dp[n-1][j]==true){
			int s1 = j;
			int s2 = totsum-j;
			mini = min(mini, abs(s1-s2));
		}
	}
	return mini;


}

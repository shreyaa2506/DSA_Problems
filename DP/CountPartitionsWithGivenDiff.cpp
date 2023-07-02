#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int f(int ind, int target, vector<int>&arr,vector<vector<int>>&dp){
	
	if(ind==0){
		if(target==0 && arr[0]==0)return 2;
		if(target==0 || target==arr[0])return 1;
		return 0;
	}
	if(dp[ind][target]!=-1)return dp[ind][target];
	int notpick = f(ind-1, target,arr,dp);
	int pick = 0;
	if(arr[ind]<=target)pick  = f(ind-1, target-arr[ind],arr,dp);
	return dp[ind][target]=(notpick+pick)%mod;
	 

}
int findWays(vector<int>& arr, int k)
{
	
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
	
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totsum = 0;
    for(int i =0; i<arr.size();i++){
        totsum+=arr[i];
    }
    if(totsum-d<0 || (totsum-d)%2!=0)return false;
    return findWays(arr,(totsum-d)/2);
}

int f(int ind, int target, vector<int>&arr){
	if(target == 0)return 1;
	if(ind==0)return arr[0]==target;

	int notpick = f(ind-1, target,arr);
	int pick = 0;
	if(arr[ind]<=target)pick  = f(ind-1, target-arr[ind],arr);
	return notpick+pick;

}

int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	return f(n-1,k,arr);
}

//memoization
int f(int ind, int target, vector<int>&arr,vector<vector<int>>&dp){
	if(target == 0)return 1;
	if(ind==0){
		if(target==0 && arr[0]==0)return 2;
		if(target==0 || target==arr[0])return 1;
		return 0;
	}
	if(dp[ind][target]!=-1)return dp[ind][target];
	int notpick = f(ind-1, target,arr,dp);
	int pick = 0;
	if(arr[ind]<=target)pick  = f(ind-1, target-arr[ind],arr,dp);
	return dp[ind][target]=notpick+pick;
	 

}

int findWays(vector<int>& arr, int k)
{
	
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return f(n-1,k,arr,dp);
	
}

//spavce optimizaiton
int findWays(vector<int>& arr, int k)
{
	sort(arr.begin(),arr.end());
	int n = arr.size();
	vector<vector<int>>dp(n,vector<int>(k+1,0));
	vector<int>prev(k+1,0);
	vector<int>cur(k+1,0);
	prev[0]=cur[0]  = 1;
	if(arr[0]<=k)prev[arr[0]]= 1;
	for(int ind = 1; ind<n;ind++){
		for(int target = 1; target<=k;target++){
			
			int notpick = prev[target];
			int pick = 0;
			if(arr[ind]<=target)pick  = prev[target-arr[ind]];
			cur[target]=notpick+pick;
		}
		prev = cur;
	}

	return prev[k];
}
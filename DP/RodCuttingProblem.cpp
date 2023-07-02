//memoization
int f(int ind, int length,  vector<int>&price,vector<vector<int>>&dp){
	if(ind==0)return length*price[0];
	if(dp[ind][length]!=-1)return dp[ind][length];
	int nottake = f(ind-1, length, price,dp);
	int take = INT_MIN;
	int rodlen= ind+1;
	if (rodlen<=length)take = price[ind]+ f(ind, length-rodlen , price,dp);
	return dp[ind][length]=max(take,nottake);
}


int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1,-1));
	return f(n-1,n,price,dp);
}

//tabulation

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1,-1));
	for(int i = 0; i<=n;i++)dp[0][i]=i*price[0];
	for(int ind = 1; ind<n;ind++){
		for(int length = 0; length<=n;length++ ){
			int nottake = dp[ind-1][length] ;
			int take = INT_MIN;
			int rodlen= ind+1;
			if (rodlen<=length)take = price[ind]+ dp[ind][ length-rodlen] ;
			dp[ind][length]=max(take,nottake);
		}
	}
	return dp[n-1][n];
}
//SpaceOptimization
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>>dp(n, vector<int>(n+1,0));
	vector<int>prev(n+1,0);
	vector<int>cur(n+1,0);
	
	for(int i = 0; i<=n;i++)prev[i]=i*price[0];
	for(int ind = 1; ind<n;ind++){
		for(int length = 0; length<=n;length++ ){
			int nottake = prev[length] ;
			int take = INT_MIN;
			int rodlen= ind+1;
			if (rodlen<=length)take = price[ind]+ cur[ length-rodlen] ;
			cur[length]=max(take,nottake);
		}
		prev=cur;
	}
	return prev[n];
}

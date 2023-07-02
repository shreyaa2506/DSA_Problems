
int f(int ind, vector<int>&weight, vector<int>&value,int maxweight,vector<vector<int>>&dp){
	if(ind ==0 ){
		if(weight[0]<=maxweight)return value[0];
		else return 0;
	}
	if(dp[ind][maxweight]!=-1)return dp[ind][maxweight];
	int notpick = f(ind-1, weight, value, maxweight,dp );
	int pick = INT_MIN;
	if(weight[ind]<=maxweight)pick = value[ind]+f(ind-1,weight,value,maxweight-weight[ind],dp);
	return dp[ind][maxweight]=max(notpick,pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,-1));
	return f(n-1,weight,value,  maxWeight,dp);
}

//Tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,0));

	for(int i = weight[0]; i<=maxWeight; i++){
		dp[0][i]= value[0];
	}
	for(int ind = 1; ind<=n-1;ind++){
		for(int w = 0; w<=maxWeight; w++){
			int notpick = dp[ind-1][ w];
			int pick = INT_MIN;
			if(weight[ind]<=w){pick = value[ind]+dp[ind-1][w-weight[ind]];}
			dp[ind][w]=max(notpick,pick);
		}
	}
	return dp[n-1][maxWeight];
	// return f(n-1,weight,value,  maxWeight,dp);
}

//Optimized Space optimization
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n, vector<int>(maxWeight+1,0));
	vector<int>prev(maxWeight+1,0);
	


	for(int i = weight[0]; i<=maxWeight; i++){
		prev[i]= value[0];
	}
	for(int ind = 1; ind<=n-1;ind++){
		for(int w = maxWeight; w>=0; w--){
			int notpick = prev[ w];
			int pick = INT_MIN;
			if(weight[ind]<=w){pick = value[ind]+prev[w-weight[ind]];}
			prev[w]=max(notpick,pick);
		}
		
	}
	return prev[maxWeight];
	// return f(n-1,weight,value,  maxWeight,dp);
}
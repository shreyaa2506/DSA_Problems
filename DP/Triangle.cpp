//Memoization
#include <bits/stdc++.h> 

int f(int i , int j , vector<vector<int>>& triangle, int n,vector<vector<int>>dp){
	if(i==n-1)return triangle[n-1][j];
	if(dp[i][j]!=-1)return dp[i][j];
	int d = triangle[i][j]+ f(i+1,j,triangle,n,dp);
	int dg = triangle[i][j]+ f(i+1, j+1, triangle,n,dp);
	dp[i][j]=min(d,dg);
	return dp[i][j];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	
	vector<vector<int>>dp(n,vector<int>(n,-1));
	int i = 0; 
	int j = 0;
	return f(i,j,triangle,n,dp);
}

//Tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){
	
	vector<vector<int>>dp(n,vector<int>(n,0));
	// int i = 0; 
	// int j = 0;
	// return f(i,j,triangle,n,dp);
	for(int i = 0; i<n;i++){
		dp[n-1][i] = triangle[n-1][i];
	}

	for(int i = n-2; i>=0;i--){
		for(int j = i ; j>=0; j--){
			int d = triangle[i][j]+ dp[i+1][j];
			int dg = triangle[i][j]+ dp[i+1][j+1];
			dp[i][j]= min(d,dg);

		}
	}
	return dp[0][0];
}

//Space Optimization
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<int>front(n,0),cur(n,0);
	vector<vector<int>>dp(n,vector<int>(n,0));
	// int i = 0; 
	// int j = 0;
	// return f(i,j,triangle,n,dp);
	for(int i = 0; i<n;i++){
		front[i] = triangle[n-1][i];
	}

	for(int i = n-2; i>=0;i--){
		for(int j = i ; j>=0; j--){
			int d = triangle[i][j]+ front[j];
			int dg = triangle[i][j]+ front[j+1];
			cur[j]= min(d,dg);

		}
		front = cur;
	}
	return front[0];
}
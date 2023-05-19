//Memoization
#include <bits/stdc++.h> 
int func(int ind,vector<int>&heights,vector<int>&dp){
    if (ind==0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int left = func(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = func(ind-2,heights,dp )+ abs(heights[ind]-heights[ind-2]);
    }
    dp[ind]= min(left,right);
    return dp[ind];

}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    return func(n-1,heights,dp);
}
//Tabulation 
#include <bits/stdc++.h> 
int func(int ind,vector<int>&heights,vector<int>&dp){
    dp[0]=0;
    dp[1]= dp[0]+abs(heights[1]-heights[0]);
    
    for(int i =2;i<=ind;i++){
        dp[i]= min(dp[i-1]+abs(heights[i]-heights[i-1]),
        dp[i-2]+ abs(heights[i]-heights[i-2]));
    }
    
   
    return dp[ind];

}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    return func(n-1,heights,dp);
}
//Space Optimization
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    
    int prev2=0;
    int prev1= 0;
    int curr=0;
    for(int i =1;i<n;i++){
        int left = prev2+abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if (i>1){
            right = prev1+ abs(heights[i]-heights[i-2]);
        }

        curr= min(left,right);
        
        prev1=prev2;
        prev2=curr;
    }
    
   
    return prev2;
}
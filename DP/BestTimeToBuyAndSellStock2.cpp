//normal
long f(int ind, int buy, long *values, int n){

    if(ind==n)return 0;
    long profit =0;
    if(buy){
        profit = max((-values[ind]+f(ind+1,0,values,n)),f(ind+1,1,values,n));
    }
    else{
        profit = max((values[ind]+f(ind+1,1,values,n)), f(ind+1,0,values,n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    return f(0,1,values, n);
}

//memoization

#include <bits/stdc++.h> 
long f(int ind, int buy, long *values, int n,vector<vector<long long>>&dp){

    if(ind==n)return 0;
    long profit =0;
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    if(buy){
        profit = max((-values[ind]+f(ind+1,0,values,n,dp)),f(ind+1,1,values,n,dp));
    }
    else{
        profit = max((values[ind]+f(ind+1,1,values,n,dp)), f(ind+1,0,values,n,dp));
    }
    return dp[ind][buy]=profit;
}

long getMaximumProfit(long *values, int n)
{
    vector<vector<long long>>dp(n,vector<long long>(2,-1));
    return f(0,1,values, n,dp);
}

//Tabulation
long getMaximumProfit(long *values, int n)
{
    
    vector<vector<long long>>dp(n+1,vector<long long>(2,0));
    for(int buy =0 ; buy<=1; buy++)dp[n][buy]=0;
    for(int ind = n-1; ind>=0;ind--){
        for(int buy = 0; buy<=1;buy++){
            long profit =0;
            if(buy){
                profit = max((-values[ind]+dp[ind+1][0]),dp[ind+1][1]);
            }
            else{
                profit = max((values[ind]+dp[ind+1][1]), dp[ind+1][0]);
            }
             dp[ind][buy]=profit;
        }
       

    }

   return dp[0][1];
}

//SpaceOptimization
long getMaximumProfit(long *values, int n)
{
    
    vector<vector<long long>>dp(n+1,vector<long long>(2,0));
    vector<long>ahead(2,0),cur(2,0);
    for(int buy =0 ; buy<=1; buy++)ahead[buy]=0;
    for(int ind = n-1; ind>=0;ind--){
        for(int buy = 0; buy<=1;buy++){
            long profit =0;
            if(buy){
                profit = max((-values[ind]+ahead[0]),ahead[1]);
            }
            else{
                profit = max((values[ind]+ahead[1]), ahead[0]);
            }
             cur[buy]=profit;
        }
        ahead = cur;
       

    }

   return ahead[1];
}


//UsingFourVariables
long getMaximumProfit(long *values, int n)
{
    
    // vector<vector<long long>>dp(n+1,vector<long long>(2,0));
    long aheadBuy, aheadNotBuy, curBuy, curNotBuy;
    aheadBuy = aheadNotBuy =0;
    
    for(int ind = n-1; ind>=0;ind--){
        
           
            
            curBuy = max((-values[ind]+aheadNotBuy),aheadBuy);
            
           
            curNotBuy = max((values[ind]+aheadBuy), aheadNotBuy);
            
        
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
       

    }

   return aheadBuy;
}
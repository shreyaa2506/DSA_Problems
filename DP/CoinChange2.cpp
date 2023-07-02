//memoization
#include<bits/stdc++.h>
long f(int ind, int target, int*a,vector<vector<long>>&dp){
    if(ind==0){
        return(target%a[0]==0);
       
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    long nottake = f(ind-1,target,a,dp);
    long take = 0;
    if(a[ind]<=target)take = f(ind,target-a[ind],a,dp);

    return dp[ind][target]=take+nottake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,-1));

    return f(n-1,value,denominations,dp);   
}

//Tabulation
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,0));
    for(int target = 0 ; target<=value;target++){
        dp[0][target]=(target%denominations[0]==0);
    }
    for(int ind=1; ind<n;ind++){
        for(int target=0 ; target<=value;target++){
                long nottake = dp[ind-1][target];
                long take = 0;
                if(denominations[ind]<=target)take = dp[ind][target-denominations[ind]];

                dp[ind][target]=take+nottake;
        }
    }

    return dp[n-1][value];
}

//SpaceOptimization
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // vector<vector<long>>dp(n,vector<long>(value+1,0));
    vector<long>prev(value+1,0);
    vector<long>cur(value+1,0);
    for(int target = 0 ; target<=value;target++){
        prev[target]=(target%denominations[0]==0);
    }
    for(int ind=1; ind<n;ind++){
        for(int target=0 ; target<=value;target++){
                long nottake = prev[target];
                long take = 0;
                if(denominations[ind]<=target)take = cur[target-denominations[ind]];

                cur[target]=take+nottake;
        }
        prev=cur;
    }

    return prev[value];
}
//Memoization

int f(int ind, int target, vector<int>&num, vector<vector<int>>&dp){
    if(ind==0){
        if(target%num[0] == 0) return target/num[0];
         return 1e9;
    }
    if(dp[ind][target]!=-1)return dp[ind][target];
    int notpick = f(ind-1,target,num,dp);
    int pick = INT_MAX;
    if(num[ind]<=target)pick = 1+f(ind,target-num[ind],num,dp);
    return dp[ind][target]=min(pick,notpick);
}
int minimumElements(vector<int> &num, int x)
{
    
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans =  f(n-1,x,num,dp);
    if(ans>=1e9)return -1;
    return ans;
}

//Tabulation
int minimumElements(vector<int> &num, int x)
{
    
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int t=0 ; t<=x;t++){
        if( t%num[0]==0)dp[0][t]=t/num[0];
        else dp[0][t]=1e9;
        }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0; target<=x;target++){
                int notpick = dp[ind-1][target];
                int pick = 1e9;
                if(num[ind]<=target)pick = 1+dp[ind][target-num[ind]];
                dp[ind][target]=min(pick,notpick);
        }
    }
    int ans = dp[n-1][x];
    if(ans>=1e9)return -1;
    return ans;
}

//SpaceOptimization
int minimumElements(vector<int> &num, int x)
{
    
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    vector<int>prev(x+1,0);
    vector<int>cur(x+1,0);
    for(int t=0 ; t<=x;t++){
        if( t%num[0]==0)prev[t]=t/num[0];
        else prev[t]=1e9;
        }
    
    for(int ind=1; ind<n;ind++){
        for(int target=0; target<=x;target++){
                int notpick = prev[target];
                int pick = 1e9;
                if(num[ind]<=target)pick = 1+cur[target-num[ind]];
                cur[target]=min(pick,notpick);
        }
        prev=cur;
    }
    int ans = prev[x];
    if(ans>=1e9)return -1;
    return ans;
}
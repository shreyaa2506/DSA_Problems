long f(int ind, int buy,int cap, vector<int>&values, int n){

    if(ind==n || cap==0)return 0;
    int profit =0;
    if(buy){
        profit = max((-values[ind]+f(ind+1,0,cap,values,n)),f(ind+1,1,cap,values,n));
    }
    else{
        profit = max((values[ind]+f(ind+1,1,cap-1,values,n)), f(ind+1,0,cap,values,n));
    }
    return profit;
}
int maxProfit(vector<int>& prices, int n)
{
    return f(0,1,2,prices,n);
}

//Memoization
long f(int ind, int buy,int cap, vector<int>&values,vector<vector<vector<int>>>&dp, int n){

    if(ind==n || cap==0)return 0;
    int profit =0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    if(buy){
        profit = max((-values[ind]+f(ind+1,0,cap,values,dp,n)),f(ind+1,1,cap,values,dp,n));
    }
    else{
        profit = max((values[ind]+f(ind+1,1,cap-1,values,dp,n)), f(ind+1,0,cap,values,dp,n));
    }
    return dp[ind][buy][cap]=profit;
}
int maxProfit(vector<int>& prices, int n)
{
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return f(0,1,2,prices,dp,n);
}

//Space optimization
int maxProfit(vector<int>& values, int n)
{
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    vector<vector<int>>after(2,vector<int>(3,0));
    vector<vector<int>>cur(2,vector<int>(3,0));


    for(int ind = n-1 ; ind>=0;ind--){
        for(int buy = 0 ; buy<=1; buy++){
            for(int cap = 1 ; cap<=2;cap++){
                     if(buy){
                            cur[buy][cap]= max((-values[ind]+after[0][cap]),after[1][cap]);
                        }
                    else{
                        cur[buy][cap]=max((values[ind]+after[1][cap-1]), after[0][cap]);
                        }
                    
            }
        }
        after = cur;
    }
    return after[1][2];
}
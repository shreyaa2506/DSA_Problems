//Recursive
 long long int solve(int h){
        if(h==0 || h==1)return 1;
        long long int mod = 1000000007;
        long long int ans = (solve(h-1)*(solve(h-1)+ 2*solve(h-2)%mod)%mod)%mod;
        return ans;
    }
    long long int countBT(int h) { 
        
        return solve(h);
    }

    //Memoization

    long long int solve(int h, vector<long long int>&dp){
         long long int mod = 1000000007;
       if(h==0 || h==1)return 1;
        if(dp[h]!=-1)return dp[h];
       
        dp[h] = (solve(h-1,dp)*(solve(h-1,dp)+ 2*solve(h-2,dp)%mod)%mod)%mod;
        return dp[h];
    }
    long long int countBT(int h) { 
        vector<long long int>dp(h+1,-1);
        return solve(h,dp);
    }

    //Tabulaiton
     long long int countBT(int h) { 
        vector<long long int>dp(h+1,0);
         long long int mod = 1000000007;
        dp[0]=1;
        dp[1]=1;
        
        for(int i = 2; i<=h; i++){
             dp[i] = (dp[i-1]*(dp[i-1] + (2*dp[i-2])%mod)%mod)%mod;
        }
        
        return dp[h];
    }
    //Space Optimization

    long long int countBT(int h) { 
        vector<long long int>dp(h+1,0);
        vector<long long int>cur(h+1,0);
         long long int mod = 1000000007;
        long long int prev1=1;
        long long int prev2=1;
        
        for(int i = 2; i<=h; i++){
             long long int cur = (prev1*(prev1 + (2*prev2)%mod)%mod)%mod;
             prev2 = prev1;
             prev1 = cur;
        }
        
        
        return prev1;
    }
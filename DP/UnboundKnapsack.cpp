 int solve(int ind, int w, int val[], int wt[],vector<vector<int>>&dp){
        if(ind==0){
            return ((int)(w/wt[0]))*val[0];
        }
        if(dp[ind][w]!=-1)return dp[ind][w];
        int notpick = 0+ solve(ind-1, w,val,wt,dp);
        int pick = 0;
        if(wt[ind]<=w){
            pick = val[ind]+ solve(ind, w-wt[ind],val,wt,dp);
        }
        return dp[ind][w]= max(pick,notpick);
        
        
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
       return solve(N-1, W, val,wt,dp); 
       
    }

    //Tabulation
     int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        for(int i =0 ; i<=W;i++){
            dp[0][i] = ((int)(i/wt[0]))*val[0];
            
        }
        
        for(int ind = 1; ind<N;ind++){
            for(int weight = 0 ; weight <=W;weight++){
                 int notpick = 0+ dp[ind-1][weight];
                int pick = 0;
                if(wt[ind]<=weight){
                    pick = val[ind]+ dp[ind][weight-wt[ind]];
                }
                dp[ind][weight]= max(pick,notpick);
            }
        }
       return dp[N-1][ W];
       
    }

    //Space Optimization
     int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N,vector<int>(W+1,0));
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        for(int i =0 ; i<=W;i++){
            prev[i] = ((int)(i/wt[0]))*val[0];
            
        }
        
        for(int ind = 1; ind<N;ind++){
            for(int weight = 0 ; weight <=W;weight++){
                 int notpick = 0+ prev[weight];
                int pick = 0;
                if(wt[ind]<=weight){
                    pick = val[ind]+ curr[weight-wt[ind]];
                }
                curr[weight]= max(pick,notpick);
            }
            prev=curr;
        }
       return prev[ W];
       
    }
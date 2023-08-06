//Based on LIS logic
 int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        int maxi =0;
        for(int i = 0 ; i<n;i++){
            for(int j =0; j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=1+dp[j];
                }
            }
            maxi = max(dp[i],maxi);
        }
        return maxi;
    }
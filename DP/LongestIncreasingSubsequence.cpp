//Memoization
    int solve(vector<int>nums, int n, int curr, int prev,vector<vector<int>>&dp){
        if (curr == n)return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int take = 0; 
        if(prev == -1 || nums[curr]>nums[prev]){
            take = 1+solve(nums,n,curr+1, curr,dp);
        }
        int nottake = solve(nums,n,curr+1,prev,dp);
        return dp[curr][prev+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1,-1));

        return solve(nums,n,0,-1,dp);
    }


//Tabulation

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int take = 0; 
                if(prev == -1 || nums[curr]>nums[prev]){
                    take = 1+dp[curr+1] [curr+1];
                }
                int nottake = dp[curr+1][prev+1];
                dp[curr][prev+1]= max(take,nottake);
                    }
        }

        return dp[0][-1+1];
    }


int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,0));
        vector<int>curRow(n+1,0);
        vector<int>nextRow(n+1,0);
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1;prev--){
                int take = 0; 
                if(prev == -1 || nums[curr]>nums[prev]){
                    take = 1+curRow[curr+1];
                }
                int nottake = nextRow[prev+1];
                curRow[prev+1]= max(take,nottake);
                    }
                   nextRow=curRow;
        }

        return nextRow[-1+1];
    }
//Better Tabulation
   int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
    vector<int>dp(n,1);
    int maxi = 1;
    for(int i =0 ; i<n;i++){
        for(int j =0 ; j<i;j++){
            if (arr[j]<arr[i]){
                dp[i]= max(dp[i], 1+dp[j]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
    }

//BinarySearch


    int binSea(int n, vector<int>nums){
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i = 1 ; i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }
            else{
                int index = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }   

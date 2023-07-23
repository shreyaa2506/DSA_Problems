int solve(vector<int>& nums, int target,vector<int>&dp){
        dp[0]=1;
        if(dp[target]!=-1)return dp[target];
        int count =0;
        for(int i =  0 ; i<nums.size(); i++){
            if(nums[i]<=target){
            

            
             count += solve(nums, target-nums[i],dp);
            }
        }
        return dp[target]= count;
     }
    int combinationSum4(vector<int>& nums, int target) {

        vector<int>dp(target+1,-1);
        return solve(nums,target,dp);
    }
//Tabulation
 int combinationSum4(vector<int>& nums, int target) {

         vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1; // Base case: There is one way to get a sum of 0, which is by not selecting any element.

    for (int i = 1; i <= target; i++) {
        for (int num : nums) {
            if (i >= num) {
                dp[i] += dp[i - num];
            }
        }
    }

    return dp[target];
    }
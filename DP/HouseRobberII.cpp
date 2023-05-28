//https://leetcode.com/problems/house-robber-ii/description/
class Solution {
public:
     int func(vector<int>&nums){
        // if (i<0){
        //     return 0;
        // }
        // if(dp[i]!=-1){
        //     return dp[i];
        // }
        // if (i==0){
        //     return nums[0];
        // }
        
        // int pick = nums[i]+func(i-2,nums,dp);
        // int notpick = 0+func(i-1,nums,dp);
        // dp[i]=max(pick,notpick);
        // return dp[i];
        int prev = nums[0];
        int prev2 = 0;
        for(int i =1; i<nums.size();i++){
            int take = nums[i];
            if(i>1){
                take+=prev2;
            }
            int nottake= prev+0;
            int curi=max(take,nottake);
            prev2=prev;
            prev=curi;
           
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        
        vector<int>temp1;
        vector<int>temp2;
        if(nums.size()==1){
            return nums[0];
        }
        for(int i =1; i<nums.size();i++){
            temp1.push_back(nums[i]);
        }
        for(int i =0; i<nums.size()-1;i++){
            temp2.push_back(nums[i]);
        }
        return (max(func(temp1),func(temp2)));


    }
};
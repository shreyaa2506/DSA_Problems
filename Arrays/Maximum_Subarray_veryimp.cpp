class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxsum= nums[0];
       int cursum=0;
       int n = nums.size();
       for(int i =0; i<n;i++){
           cursum= cursum+nums[i];
           maxsum = max(cursum,maxsum);
           if(cursum<0){
               cursum=0;
           }
       } 
       return maxsum;
    }
};
//  Longest Subarray of 1's After Deleting One Element
 class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocount = 0; 
        int longestWindow = 0 ;
        int start = 0;

        for(int i = 0; i<nums.size(); i++){
            zerocount+=(nums[i]==0);

            while(zerocount>1){
                zerocount-=(nums[start]==0);
                start++;
            }
            longestWindow = max(longestWindow, i-start);

        }
        return longestWindow;
    }
};
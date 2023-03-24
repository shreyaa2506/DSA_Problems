long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        
        int i =0;
        int n = nums.size();
        while(i<n){
            if (nums[i]==0){
                long long count = 0;
                while(i<n && nums[i]==0){
                    count++;
                    i++;
                }
                    long long val = (count *(count+1))/2;
                    ans+=val;
            }
        
            else{
            i++;
             }
        }
        return ans;
    }
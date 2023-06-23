double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum=0;
        for(int i =0; i<k;i++){
            sum+=nums[i];
        }
        int max = sum;
        for(int i =k; i<n;i++){
            sum+=nums[i]-nums[i-k];
            if(sum>max){
                max=sum;
            }
        }
        return (max*1.0)/k;

    }
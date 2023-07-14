 vector<int> singleNumber(vector<int> nums) 
    {
        
        // return ans;
        int n = nums.size();
        int xor1 =0;
        for(int i =0 ; i<n;i++){
            xor1 = xor1^nums[i];
        }
        int count = 0;
        while(xor1!=0){
            if(xor1&1==1)break;
            else{count++;
            xor1 = xor1>>1;}
        }
        
        int xor2=0;
        int xor3=0;
        for(int i =0 ; i<n;i++){
            if(nums[i]&(1<<count))xor2= xor2^nums[i];
            else xor3= xor3^nums[i];
        }
        vector<int>ans;
        ans.push_back(xor2);
        ans.push_back(xor3);
        sort(ans.begin(),ans.end());
        return ans;
        }
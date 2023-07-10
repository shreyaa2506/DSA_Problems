 vector<int> productExceptSelf(vector<int>& nums) {

        vector<int>op;
        int n = nums.size();
        int product = 1;

        for(int i =0 ; i<n;i++){
            product = product*nums[i];
            op.push_back(product);
        }
        product = 1;
        for(int i =n-1; i>0; i--){
            op[i]= op[i-1]*product;
            product = product * nums[i];
        }
        op[0] = product;
        return op;
        
    }
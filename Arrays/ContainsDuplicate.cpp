 bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int i =0;i<nums.size();i++){
            count[nums[i]]++;
        }
        for(auto i:count){
            if (i.second>1){
                return true;
            }
        }
        return false;
    }


    // int c =0;
    // for(int i =0; i<n;i++){
    //     for(int j =i;j<n;j++){
    //         if(((i[0]^j[0])+ (i[1]^j[1]))==k){
    //             c+=1;
    //         }
    //     }

    // }
    // return c;
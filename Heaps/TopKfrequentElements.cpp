// 347. Top K Frequent Elements

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]



int n=nums.size();
        unordered_map<int,int>mp;
        vector<int> Res;
       
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> m;
        for( auto i : mp)
        {
            m.push(make_pair( i.second, i.first));
        }
        
        for( int i =0;i<k ; i++)
        {
            Res.push_back( m.top().second);
            m.pop();
        }
      
        return Res;
    }
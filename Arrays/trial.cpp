#include <iostream>
#include <vector>
#include <unordered_map>

int maxEqualSubsequenceLength(std::vector<int>& nums) {
    int maxLength = 0;
    std::unordered_map<int, int> countMap;
    
    for (int num : nums) {
        for (int i = -1; i <= 1; i++) {
            int modifiedNum = num + i;
            countMap[modifiedNum]++;
        }
    }
    
    for (auto it = countMap.begin(); it != countMap.end(); ++it) {
        maxLength = std::max(maxLength, it->second);
    }
    
    return maxLength;
}

int main() {
    std::vector<int> nums = {2, 5, 1, 2};
    int maxLength = maxEqualSubsequenceLength(nums);
    
    std::cout << "Maximum length of subsequence with equal number of elements: " << maxLength << std::endl;
    
    return 0;
}


//2
#include <iostream>
#include <vector>
#include <unordered_map>

int countPairsWithDistanceK(int k, const std::vector<std::pair<int, int>>& coordinates) {
    int count = 0;
    std::unordered_map<int, int> distanceMap;

    for (int i = 0; i < coordinates.size(); i++) {
        for (int j = i + 1; j < coordinates.size(); j++) {
            int distance = (coordinates[i].first ^ coordinates[j].first) +
                           (coordinates[i].second ^ coordinates[j].second);

            if (distance == k)
                count++;
        }
    }

    return count;
}

int main() {
    int k = 3;
    std::vector<std::pair<int, int>> coordinates = {{0, 1}, {2, 3}, {1, 3}};
    int result = countPairsWithDistanceK(k, coordinates);

    std::cout << "Number of pairs with distance " << k << ": " << result << std::endl;

    return 0;
}



bool set = 0;
for(int i =0; i<n;i++){
    if(arr[i]=='('){
         st.push('(');
          set=1;}
    else if (arr[i]=='('  && st.top()==')') {
        if(set==1){
            ans++; 
        }
        st.pop();
         
        set=0;
    }
    return ans;
}

int t;
cin>>t;
int ans = 0;
while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool set = 1;
    for(int i =0;i<n;i++){
        if(s[i]=='('){
            set = 1;
        }
        else if (s[i]==')'&& set ==1){
            ans++;
            set =0;
        }
    }
    return ans;
}


unordered_map<pair<int,int>,int>mp;
for(int i =0; i<N;i++){
    map[arr[i]]++;
}
for(int i =0; i<N;i++){
    for(intv i =0;i<k;i++){
        ans+=map[arr[i].first^x, arr[i].second^(k-x)]
    }
}
return ans;


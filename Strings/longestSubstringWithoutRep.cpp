class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>arr(256,-1);
        
        int start = -1;
    
        int maxlen = 0;
        for(int i =0; i<s.size(); i++){
            
            if (arr[s[i]]>start){
                start= arr[s[i]];
                
                }
            arr[s[i]]=i;
            maxlen = max(maxlen,i-start);
             
            }
        
        return maxlen;
        
    }
};
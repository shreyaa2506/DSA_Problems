int helper(int i, string s, set<string>st,vector<int>&dp){
        if(i==s.size())return 1; 
        if(dp[i]!=-1)return dp[i];
        string temp;
        for(int j = i ; j<s.size();j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(helper(j+1, s, st,dp))return dp[i]= 1;
            }
        }
       return dp[i]= 0;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        int n = s.size();
        vector<int>dp(n+1,-1);
        for(auto it:wordDict){
            st.insert(it);
        }
        return helper(0,s,st,dp);
    }

    //Tabulaiton
    bool wordBreak(string s, vector<string>& wordDict) {
       set<string> st;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1; // Base case: an empty string is always breakable

    for (auto it : wordDict) {
        st.insert(it);
    }

    for (int i = n - 1; i >= 0; i--) {
        string temp;
        for (int j = i; j < s.size(); j++) {
            temp += s[j];
            if (st.find(temp) != st.end() && dp[j + 1]) {
                dp[i] = 1;
                break; // If we find a valid word, no need to continue checking
            }
        }
    }

    return dp[0];
    }
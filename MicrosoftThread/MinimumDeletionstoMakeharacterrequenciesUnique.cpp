int minDeletions(string s) {
        int n = s.size();
        vector<int>mp1(26,0);
        for(int i =0 ; i<s.size(); i++){
            mp1[s[i]-'a']++;
        }
        int op =0;
        sort(mp1.begin(),mp1.end());
        for (int i = 24; i >= 0; i--) {
            
            if(mp1[i] == 0) break; 
            if(mp1[i] >= mp1[i+1]){
                int prev = mp1[i]; 
                mp1[i] = max(0, mp1[i+1] -1); 
                op+= prev - mp1[i]; 
            }
        }
        
        return op;
    }
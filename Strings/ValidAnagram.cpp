bool isAnagram(string s, string t) {
        vector<int>arr(26);
        vector<int>arr2(26);
        for(int i =0; i<s.length();i++){
            arr[s[i]-'a']++;
        }
        for(int j =0; j<t.length();j++){
            arr2[t[j]-'a']++;
        }
        for(int i =0;i<26;i++){
            if(arr[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
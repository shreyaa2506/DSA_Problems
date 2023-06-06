string removeConsecutiveCharacter(string s)
    {
        string str="";
        int l= s.length();
        for(int i =1; i<=l;i++){
            if (s[i]!=s[i-1]){
                str+=s[i-1];
            }
        }
        return str;
    }
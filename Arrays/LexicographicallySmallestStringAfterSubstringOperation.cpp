string smallestString(string s) {
        int n = s.length();
        int i =0;

        while(s[i]=='a' && i<n){
            i++;
        }
        if(i<n){
            while(i<n && s[i]!='a'){
                s[i]--;
                i++;
            }
        }
        else{
            s[n-1]='z';
        }
        return s;

    }
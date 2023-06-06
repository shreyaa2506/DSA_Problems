 bool valid(char ch){
        if ((ch>='a' && ch<='z')|| (ch>='0'&& ch<='9') || (ch>='A'&& ch<='Z')){
            return true;
        }
        else{
            return false;
        }
    }

    char tolower(char ch){
        if ((ch>='a'&& ch<='z')|| (ch>='0'&& ch<='9')){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkpalindrome(string s){
        int st=0;
        int e = s.length()-1;
        while(st<=e){
            if (s[st] != s[e]){
                return false;
            }
            else{
                st++;
                e--;
            }

        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        // string temp="";
        // for (int i =0; i<s.length();i++){
        //     if (valid(s[i])){
        //         temp.push_back(s[i]);
        //     }
        // }
    

        // for (int i =0; i<temp.length();i++){
        //     temp[i]=tolower(temp[i]);
        // }

        // return checkpalindrome(temp);
        string temp ="";
        for(int i =0; i<s.length();i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }
        for(int i =0; i<temp.length();i++){
            temp[i]=tolower(temp[i]);
        }
        return checkpalindrome(temp);
    }
 bool isValid(string s) {
        stack<int>st;
        for(int i =0; i<s.length();i++){
            if(s[i]=='('|| s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            // else if((s[i]==')' && st.top()=='(')|| (s[i]==']' && st.top()=='[') ||
            //  (s[i]=='}' && st.top()=='{')){
            //      st.pop();
            //  }
            
            else{
                if(st.size()==0) return false;
                if (s[i]==']'&& st.top()!='[') return false;
                if (s[i]==')'&& st.top()!='(') return false;
                if (s[i]=='}'&& st.top()!='{') return false;
                st.pop();
    
            }
            

        }

        if(st.size()>0) return false;
        
        return true;

       
    }
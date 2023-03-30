bool findRedundantBrackets(string &s)
{
    stack<char>temp;
    for(int i =0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            temp.push(s[i]);
        }
        else if (s[i]==')'){
            bool redundant = true;
            while(temp.top()!='('){
                char top = temp.top();
                if(top == '+'|| top=='-' || top == '*' || top == '/'){
                    redundant =false;
                }
                temp.pop();
            }
            if (redundant == true) {
              return true;
            }
            temp.pop();
        }
    }
    return false;


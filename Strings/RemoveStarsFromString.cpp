class Solution {
public:
    string removeStars(string s) {
      string ans = "";
      stack<char>st;
      for(int i =0;i<s.size();i++){
          if(s[i]!='*'){
              st.push(s[i]);
          }
          else if(s[i]=='*'){
              st.pop();
          }

      }
      
      int i =0;
      while(!st.empty()){
          ans+=st.top();
          st.pop();
      }
      
      reverse(ans.begin(), ans.end());
      return ans;
      
       
    }
};
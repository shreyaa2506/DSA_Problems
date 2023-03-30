#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  stack<char>s;
  int a=0;
  int b =0;

  if (str.length()%2==1){
    return -1;
  }

  for(int i =0; i<str.length(); i++){
        if(str[i]=='{'){
          s.push(str[i]);
        } 
        
        else {
          if (!s.empty()&& s.top()== '{' ){
            s.pop();
          }
          else{
            s.push(str[i]);
          }
        }
  }
  while(!s.empty()){
    if (s.top()=='{'){
      a++;
    }
    else{
      b++;
    }
    s.pop();
  }
  return (((a+1)/2) + ((b+1)/2));

}
string reverseWord(string str){
    
  string str1 = "";
  for(int i = str.length();i>=0;i--){
        str1+=str[i];      
  }
  return str1;
}

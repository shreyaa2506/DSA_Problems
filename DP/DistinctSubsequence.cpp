int f(int i , int j , string s, string t){
    if(j<0)return 1;
    if(i<0)return 0;
    if(s[i]==t[j]){
        return f(i-1,j-1,s,t)+f(i-1,j,s,t);
    }
    return f(i-1,j,s,t);
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
   
    return f(lt-1,ls-1,t,s);
} 
//Memoization
#include <bits/stdc++.h> 
int f(int i , int j , string s, string t,vector<vector<int>>dp){
    if(j<0)return 1;
    if(i<0)return 0;
    if(s[i]==t[j]){
        return dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    }
    return dp[i][j]= f(i-1,j,s,t,dp);
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
   vector<vector<int>>dp(lt,vector<int>(ls,-1));
    return f(lt-1,ls-1,t,s,dp);
} 
//ByMakingIndex0
int f(int i , int j , string s, string t,vector<vector<int>>dp){
    if(j==0)return 1;
    if(i==0)return 0;
    if(s[i-1]==t[j-1]){
        return dp[i][j]= f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    }
    return dp[i][j]= f(i-1,j,s,t,dp);
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
   vector<vector<int>>dp(lt+1,vector<int>(ls+1,-1));
    return f(lt,ls,t,s,dp);
} 
class Solution{
public:
    int nCr(int n, int r){
       if(n<r)return 0;
       if((n-r)<r)r=n-r;
       int mod = 1000000007;
       vector<int>dp(r+1,0);
       dp[0]=1;
       for(int i = 1; i<=n;i++){
           for(int j = r;j>0; j--){
               dp[j]= (dp[j]+dp[j-1])%mod;
           }
       }
       return dp[r];
    }
};
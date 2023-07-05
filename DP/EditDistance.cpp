int f(int i , int j , string str1, string str2){
    if(i<0)return j+1;
    if (j<0)return i+1;
    if(str1[i]==str2[j]){
        return f(i-1,j-1,str1,str2);
        
    }
    else {
        return 1+min (f(i,j-1,str1,str2), min(f(i-1,j,str1,str2),f(i-1,j-1,str1,str2)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    return f(n-1,m-1,str1,str2);
}

//Memoization
int f(int i , int j , string str1, string str2, vector<vector<int>>&dp){
    if(i<0)return j+1;
    if (j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i]==str2[j]){
       return dp[i][j]= f(i-1,j-1,str1,str2,dp);
        
    }
    else {
        return dp[i][j]=1+min (f(i,j-1,str1,str2,dp), min(f(i-1,j,str1,str2,dp),f(i-1,j-1,str1,str2,dp)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(n-1,m-1,str1,str2,dp);
}

//Memoization with base case i==0 and j==0
int f(int i , int j , string str1, string str2, vector<vector<int>>&dp){
    if(i==0)return j;
    if (j==0)return i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(str1[i-1]==str2[j-1]){
       return dp[i][j]= f(i-1,j-1,str1,str2,dp);
        
    }
    else {
        return dp[i][j]=1+min (f(i,j-1,str1,str2,dp), min(f(i-1,j,str1,str2,dp),f(i-1,j-1,str1,str2,dp)));
    }
}

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return f(n,m,str1,str2,dp);
}


//Tabulation
int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    for(int j =0 ; j<=m;j++)dp[0][j]=j;
    for(int i =0 ; i<=n; i++)dp[i][0]= i;
    for(int i = 1 ; i<=n;i++){
        for(int j =1 ; j<=m; j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]= dp[i-1][j-1];
                    
                }
                else {
                    dp[i][j]=1+min (dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]));
                }
        }
    }
    return dp[n][m];
}

//SpaceOptimization

int editDistance(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    vector<int>prev(m+1,0);
    vector<int>cur(m+1,0);

    for(int j =0 ; j<=m;j++)prev[j]=j;
    
    for(int i = 1 ; i<=n;i++){
        cur[0]=i;
        for(int j =1 ; j<=m; j++){
            if(str1[i-1]==str2[j-1]){
                cur[j]= prev[j-1];
                    
                }
                else {
                    cur[j]=1+min (cur[j-1], min(prev[j],prev[j-1]));
                }
        }
        prev = cur;
    }
    return prev[m];
}
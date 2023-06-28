int f(int i, int j , vector<vector<int>>&grid,int n,int m,vector<vector<int>>&dp){
    if(i==n-1 && j==m-1)return grid[n-1][m-1];
    if(i>n-1 || j>m-1)return 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    int down = grid[i][j]+ f(i+1,j,grid,n,m,dp);
    int right = grid[i][j]+ f(i,j+1,grid,n,m,dp);
    return dp[i][j]=min(down,right);
    
}


int minSumPath(vector<vector<int>> &grid) {
    
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return f(0,0,grid,n,m,dp);
}

//tabulation
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    vector<int>next(n,0);
    // int dp[n][m];
    for(int i =n-1;i>=0;i--){
        vector<int>cur(m,0);
        for(int j =m-1; j>=0;j--){
            if(i==n-1 && j==m-1)cur[j]= grid[i][j];
            else{
                int down = grid[i][j];
                if(i<n-1)down+=next[j];
                else down+=1e9;

                int right = grid[i][j];
                if(j<m-1)right+=cur[j+1];
                else right+=1e9;

                dp[i][j]= min(down,right);
            }
        }
    }
    return next[0];
    // return f(0,0,grid,n,m,dp);
}

// Space Optimization

int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    vector<int>next(n,0);
    // int dp[n][m];
    for(int i =n-1;i>=0;i--){
        vector<int>cur(m,0);
        for(int j =m-1; j>=0;j--){
            if(i==n-1 && j==m-1)cur[j]= grid[i][j];
            else{
                int down = grid[i][j];
                if(i<n-1)down+=next[j];
                else down+=1e9;

                int right = grid[i][j];
                if(j<m-1)right+=cur[j+1];
                else right+=1e9;

                cur[j]= min(down,right);
            }
        }
        next=cur;
    }
    return next[0];
    // return f(0,0,grid,n,m,dp);
}
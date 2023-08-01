//memoization
int func(int row, int col, vector<vector<int>>M, int rowsize, int colsize, vector<vector<int>>&memo){
        if(row<0 || row>=rowsize || col<0 || col>=colsize){
            return 0;
        }
        if(memo[row][col]!=-1)return memo[row][col];
        
        int right = M[row][col]+func(row,col+1, M, rowsize,colsize,memo);
        int rightup = M[row][col]+func(row-1, col+1, M, rowsize,colsize,memo);
        int rightdown =M[row][col]+ func(row+1, col+1, M, rowsize, colsize,memo);
        return memo[row][col]=max(right, max(rightdown , rightup));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int noOfRow = M.size();
        int noOfcol = M[0].size();
         int ans = 0;
          vector<vector<int>> memo(noOfRow, vector<int>(noOfcol, -1));
        for(int i = 0 ; i<n;i++){
            // vector<vector<int>>dp(noOfRow+1, vector<int>(noOfcol+1,0));
             ans = max(ans, func (i,0,M,noOfRow, noOfcol,memo));
        }
        return ans;
    }

    //Tabulation
       int maxGold(int m, int n, vector<vector<int>> M)
    {
        int ans=INT_MIN;
        vector<vector<int>>dp(m+2 , vector<int>(n+2,0));
        
        
              for(int j=n-1;j>=0;j--){
                  for(int i=m-1;i>=0;i--){
                      int right = M[i][j]+dp[i][j+1];
                      int rightup = (i-1<0)?INT_MIN:M[i][j]+dp[i-1][j+1];
                      int rightdown =M[i][j]+ dp[i+1][j+1];
                      dp[i][j]=max(right, max(rightdown , rightup));
                  }
              }
              
              for(int i=0;i<m;i++){
                  ans=max(ans , dp[i][0]);
              }
        return ans;
    }
//Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int ind = n-1; ind>=0;ind--){
        for(int prev_ind = ind-1; prev_ind>=-1;prev_ind--){
                int len = 0 + dp[ind+1][prev_ind+1];
                if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
                    len = max(len, 1+dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1]=len;
                    }
    }
    return dp[0][-1+1];
}

//SpaceOptimization

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    vector<int>cur(n+1,0);
    vector<int>ahead(n+1,0);
    for(int ind = n-1; ind>=0;ind--){
        for(int prev_ind = ind-1; prev_ind>=-1;prev_ind--){
                int len = 0 + ahead[prev_ind+1];
                if(prev_ind==-1 || arr[ind]>arr[prev_ind]){
                    len = max(len, 1+ahead[ind+1]);
                }
                cur[prev_ind+1]=len;
                    }
                    ahead= cur;
    }
    return cur[-1+1];
}

//BinarySearch

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i =1; i<n;i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            temp[ind]= arr[i];
        }
    }
    return temp.size();
}

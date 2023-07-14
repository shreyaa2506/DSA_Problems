long long int solve(  vector<int> &arr , int idx , int s, vector<vector<long long int>>&dp ){
    
     if( s == 0 )return 1 ;
    if( idx == 2 ) return ( s % arr[idx]  == 0 ) ;
    if(dp[idx][s]!=-1)return dp[idx][s];
    
    long long int take = 0 , ntake = 0 ; 
    if( s - arr[idx] >= 0 ) take =  solve( arr , idx , s - arr[idx],dp ) ;
    
    ntake = solve( arr , idx + 1 , s ,dp) ;
    
    
    return dp[idx][s]=take + ntake ;
}

long long int count(long long int n)
{
    vector<int> arr = {3,5,10} ;
    vector<vector<long long int>>dp(3,vector<long long int>(n+1,-1));
    return solve(arr , 0 , n ,dp);
    
}

//Tabulation
long long int count(long long int n)
{
    vector<int> arr = {3,5,10} ;
    vector<vector<long long int>>dp(4,vector<long long int>(n+1,0));
    for(int i = 0; i<=3;i++){
        dp[i][0]=1;
    }
    for(int sum =0 ;sum<=n;sum++){
        (dp[2][sum])=( (sum%arr[2])==0);
    }
    for(int idx= 2; idx>=0 ;idx--){
        for(int s=0 ; s<=n;s++){
            long long int take = 0 , ntake = 0 ; 
            if( s - arr[idx] >= 0 ) take =  dp[idx][ s - arr[idx]];
            
            ntake = dp[idx + 1][s] ;
             dp[idx][s]=take + ntake ;
        }
    }
    return dp[0][n];
    
}
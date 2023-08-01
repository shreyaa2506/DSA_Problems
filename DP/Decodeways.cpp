//Decode Ways memoization 
int numways(string s,int i,vector<int>&dp){
        if(i>=s.size())return 1;
        else if(s[i]=='0')return 0;
        else if(i==s.size()-1) return 1; //didnt include this in the 1st condition only bcoz we had to 
        //check for zero also
        if(dp[i]!=-1)return dp[i];

        else if(s[i]=='1' || (s[i]=='2' && (s[i+1]>=46 && s[i+1]<=54))) //this is the important logic.
        //I have check if it 1 then you can take either 1 or first 2. 
        // or if it 2 and the next character's ascii value lies between 0 to 6 , then also you can take
        //2 or 2 and the next character
        return dp[i]= numways(s,i+1,dp)+numways(s,i+2,dp);
        else return dp[i]= numways(s,i+1,dp);
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        return numways(s,0,dp);
    }

    //tabulation
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,0);
        if(s.size()==0 || s[0]=='0')return 0;
        dp[0]=1;
        dp[1]=1;
        
        int n = s.size();
        for(int i = 2; i<=n;i++){
            if(s[i-1]>='1'  && s[i-1]<='9'){
                dp[i]=dp[i-1];
            }
            if(s[i-2]=='1'){
                dp[i]+=dp[i-2];
            }
            else if (s[i-2]=='2' && (s[i-1]>='0' && s[i-1]<='6')){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
        
    } 
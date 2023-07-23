	int maxSubstring(string S)
	{
	   int n = S.size();
	   int maxsum=INT_MIN;
	   int sum=0;
	   for(int i = 0 ; i<n;i++){
	      int x =  (S[i]=='0')? 1:-1;
	       sum+=x;
	       if(sum>maxsum)maxsum=sum;
	       if(sum<0)sum=0;
	   }
	   return maxsum;
	}
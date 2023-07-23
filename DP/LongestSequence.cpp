  int longestSubsequence(int N, int A[])
    {
        unordered_map<int,int>m;
        int ma =0;
        for(int i = 0 ; i< N;i++){
            int l = 0 ;
            if(m[A[i]-1])l=m[A[i]-1];
            if(m[A[i]+1] and m[A[i]+1]>l)l=m[A[i]+1];
            m[A[i]]=l+1;
            ma= max(m[A[i]],ma);
        }
        return ma;
    }
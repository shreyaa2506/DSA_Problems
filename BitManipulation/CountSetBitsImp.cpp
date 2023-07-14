 int largestpowerof2inrange(int n){
        int x= 0 ; 
        while((1<<x)<=n){
            x++;
        }
        return x-1;
    }
    int countSetBits(int n)
    {
        if(n==0)return 0;
        int x = largestpowerof2inrange(n);
        int bittill2 = x*(1<<(x-1));
        int 1sfrom2xton = n-(1<<x)+1;
        int rest = n-(1<<x);
        int ans = bittill2 + 1sfrom2xton + countSetBits(rest);
        return ans;
    }
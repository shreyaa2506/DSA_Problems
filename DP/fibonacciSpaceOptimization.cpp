#include<bits/stdc++.h>
using namespace std;

int main()
{
        int n;
        cin>>n;
        int prev1= 1;
        int prev2=0;
        int curr= 0;
        if(n==0){
                return 0;
        }
        
        for(int i =2; i<=n;i++){
                curr = prev1+prev2;
                prev2= prev1;
                prev1=curr;

                
        }
        cout<<prev1;
}
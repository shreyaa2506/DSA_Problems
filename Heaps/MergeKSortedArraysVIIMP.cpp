//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class data{
    public:
    int val,apos,vpos;
    data(int v,int ap,int vp){
        val = v;
        apos = ap;
        vpos = vp;
    }
};

struct mycomp{
    bool operator()(data &d1,data &d2){
        return d1.val>d2.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        priority_queue<data,vector<data>,mycomp>pq;
        vector<int>ans;
        for(int i =0; i<k;i++){
            data d(arr[i][0],i,0);
            pq.push(d);
        }
        
        while(!pq.empty()){
            data curr = pq.top();
            pq.pop();
            ans.push_back(curr.val);
            int vp = curr.vpos;
            int ap =  curr.apos;
            if(vp+1<arr[ap].size()){
                data d(arr[ap][vp+1],ap,vp+1);
                pq.push(d);
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
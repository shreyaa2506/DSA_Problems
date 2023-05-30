//https://practice.geeksforgeeks.org/problems/minimum-difference-among-k5805/1
int minDiff(int arr[], int N, int k)
    {
        sort(arr,arr+N);
        vector<int>ans;
        for(int i =k-1;i<N;i++){
            ans.push_back(arr[i]-arr[i-k+1]);
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
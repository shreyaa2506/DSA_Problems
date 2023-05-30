//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1
vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans(n);
        stack<long long>st;
        for(int i =n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=-1;
            }
            else if(!st.empty() && arr[i]<st.top()){
                ans[i]=st.top();
            }
            else {
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                if(!st.empty())ans[i]=st.top();
                else ans[i]=-1;
            }
            st.push(arr[i]);
        }
        return ans;
    }
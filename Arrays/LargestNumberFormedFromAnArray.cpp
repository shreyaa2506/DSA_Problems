	bool static cmp(string &a, string &b){
	    return (a+b)>(b+a);
	}
	string printLargest(vector<string> &arr) {
	    string ans = "";
	    sort(arr.begin(),arr.end(),cmp);
	    for(int i =0 ; i<=arr.size()-1;i++){
	        ans+=arr[i];
	    }
	    return ans;
	}
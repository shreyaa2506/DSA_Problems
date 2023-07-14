	vector<string> AllPossibleStrings(string s){
		  
		     int n = s.size();
            vector<string>sub;
            int x = 1 << n;
            for(int i = 1; i < x; i++){
                string currentSubset;
                for(int j = 0; j < n; j++){
                    if(i & (1 << j)){
                        currentSubset+=s[j];
                    }
                }
                sub.push_back(currentSubset);
            }
            sort(sub.begin(),sub.end());
            return sub;
		}
 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3){
            set<int>ans;
            for(int i =0; i<n1; i++){
                if (binary_search(B,B+n2,A[i]) && binary_search (C,C+n3, A[i])) ans.insert(A[i]);
            }
            vector<int>final;
            for(auto x:ans) final.push_back(x);
            return final;
 }
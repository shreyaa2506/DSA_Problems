class Solution {
public:

    double dfs(unordered_map<string,vector<pair<string,double>>>&mp, string src, string dst,
    unordered_map<string,int>&visited ){
        if(mp.find(src)==mp.end())return -1.0;
        if(src==dst)return 1;
        visited[src]=1;
        for(auto node:mp[src]){
            if(visited.find(node.first)!=visited.end()) continue;
            double res = dfs(mp,node.first,dst,visited);
            if(res!=-1){
                return res*node.second;
            }
        }

        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i =0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],double(1/values[i])});
        }
        int m = queries.size();
        vector<double>ans(m);
        for(int i =0;i<m;i++){
            unordered_map<string,int>visited;
            if(mp.find(queries[i][0])==mp.end())ans[i]=-1;
            else{
                ans[i]=dfs(mp,queries[i][0],queries[i][1],visited);
            }
        }
        return ans;
    }
};
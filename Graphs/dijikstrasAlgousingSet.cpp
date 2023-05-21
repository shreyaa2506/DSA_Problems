class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        vector<int>visited(n,0);
        queue<int>q;
        for(int i =0; i<n;i++){
            if (!visited[i]){
                q.push(i);
                visited[i]=1;
                color[i]=1;

            }

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto i:graph[node]){
                    if(color[i]==-1){
                        color[i]=~color[node];
                        q.push(i);
                        visited[i]=1;
                    }
                    else if (color[i]==color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
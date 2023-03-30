#include <bits/stdc++.h> 

void topdfs(int node,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj
,stack<int>&s  ){
    
    visited[node]=1;
    for(auto i:adj[node] ){
        if(!visited[i]){
             topdfs(i,visited,adj,s);
        }
       
        
    }
    s.push(node);
   
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>>adj;
    for(int i =0; i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        
    }
    unordered_map<int,bool>visited;
    vector<int>ans;
    stack<int>s;
    for (int i =0; i<v;i++){
        if(!visited[i]){
            topdfs(i,visited,adj,s);
        }
    }

    while(!s.empty()){
       ans.push_back(s.top());
       s.pop();
   }

    return ans;
    }
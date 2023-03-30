#include<unordered_map>
#include<list>
bool checkdfs(int node,unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsvis,unordered_map<int,list<int>>&adjlist ){
  visited[node]=1;
  dfsvis[node]=1;
  for(auto i:adjlist[node]){
    if (!visited[i]){
      bool cyclefound = checkdfs(i,visited,dfsvis,adjlist);
      if(cyclefound){
        return true;
      }
    }
    else if(dfsvis[i]==1){
        return true;
    
    }
  }
  dfsvis[node]=false;
  return false;
}





int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>>adjlist;
  for(int i =0; i<edges.size();i++){
    int u = edges[i].first;
    int v = edges[i].second;
    adjlist[u].push_back(v);
    
  }

  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfsvis;
  for(int i =0; i<n;i++){
    if (!visited[i]){
      bool checkcycle = checkdfs(i,visited,dfsvis,adjlist);
      if(checkcycle== true){
        return true;
      }
    }
  }
  return false;
  }
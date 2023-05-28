#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int,int>>>adj;
    for(int i =0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w= vec[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>dist(vertices);
    for(int i =0; i<vertices; i++){
        dist[i]=INT_MAX;
    }
    set<pair<int,int>>st;
    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        auto top = *(st.begin());
        int nodedistance = top.first;
        int topnode = top.second;
        st.erase(st.begin());
        
        for(auto neighbour: adj[topnode] ) {
            if(nodedistance + neighbour.second< dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));
                if(record!=st.end()){
                    st.erase(record);
                }
                dist[neighbour.first]= nodedistance+neighbour.second;
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
                
            }
        }  
         }
         return dist;
}


// USING PRIORITY QUEUE

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
          vector<int>dist(V);
          for(int i =0; i<V;i++){
              dist[i]=1e9;
          }
          dist[S]=0;
          pq.push({0,S});
          while(!pq.empty()){
              int dis = pq.top().first;
              int node = pq.top().second;
              pq.pop();
              for(auto it:adj[node]){
                  int et = it[1];
                  int adjNode=it[0];
                  if (dis+et<dist[adjNode]){
                      dist[adjNode]=dis+et;
                      pq.push({dist[adjNode],adjNode});
                  }
                  
              }
          }
          return dist;
    }
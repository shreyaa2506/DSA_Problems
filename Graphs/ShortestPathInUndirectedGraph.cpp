unordered_map<int,list<int>>adj;
    for(int i =0; i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
		adj[v].push_back(u);
        
    }

	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;
	queue<int>q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;
	while(!q.empty()){
		int front = q.front();
		q.pop();
		for(auto i:adj[front]){
			if (!visited[i]){
				q.push(i);
				visited[i]=1;
				parent[i]=front;
			}
			
		}
	}
	vector<int>ans;
	ans.push_back(t);
	while(t!=s){
		t = parent[t];
		ans.push_back(t);
	}
	reverse(ans.begin(),ans.end());
	return ans;
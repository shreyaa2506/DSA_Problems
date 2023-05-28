//https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/?purpose=login&source=problem-page&update=google

#include <bits/stdc++.h>
using namespace std;

 
void dfs(int src,int par,vector<int> g[],vector<int>&inTime,vector<int>&outTime,int&timer){
    inTime[src] = timer++;
    for(auto x:g[src]){
        if(x!=par){
            dfs(x,src,g,inTime,outTime,timer);
        }
    }
    outTime[src] = timer++;
}
 
bool check(int x,int y,vector<int>&inTime,vector<int>&outTime){
    if(inTime[x]>inTime[y] and outTime[x]<outTime[y]) 
        return true;
    return false;
}

int main() {
	
	int timer = 1;
	 int n;
    cin>>n;
    timer = 1;
    vector<int> inTime(n+1);
	vector<int> outTime(n+1);
    vector<int> g[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0,g,inTime,outTime,timer);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int type,x,y;
        cin>>type>>x>>y;
        if(!check(x,y,inTime,outTime) and !check(y,x,inTime,outTime)){
            cout<<"NO\n";
            continue;
        }
        if(type==0){
            if(check(y,x,inTime,outTime))
                cout<<"YES\n";
            else 
                cout<<"NO\n";
        }
        else if(type==1){
            if(check(x,y,inTime,outTime))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
 
    }
 
 
 
 
    return 0;
}
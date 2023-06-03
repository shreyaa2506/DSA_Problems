//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& g) {
        int n = g.size();
        if(g[0][0] || g[n-1][n-1])return -1;
        int t=0;
        g[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        
        while(q.size()){
            int k = q.size();
            t++;
            while(k--){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x==n-1 && y==n-1)return t;
                 int dx[8]={1,-1,0,0,1,1,-1,-1};
                int dy[8]={0,0,1,-1,1,-1,1,-1};
                for(int i =0;i<8;i++){
                    int newx =x+dx[i];
                    int newy= y+dy[i];
                    if(newx>=0 && newy>=0 && newx<n && newy<n && 
                    g[newx][newy]==0){
                        g[newx][newy]=1;
                        q.push({newx,newy});
                    }
                }

            }
        }
        return -1;

    }
};
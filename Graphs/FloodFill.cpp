//https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    void bfs(int n,int m,int row, int col,vector<vector<int>>& ans,vector<vector<int>>& image,int ic,int color,int dr[],int dc[]){
        
        ans[row][col]=color;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(q.size()!=0){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+ dc[i];
                if(nr>=0 && nr<n && nc<m && nc>=0 && ans[nr][nc]!=color && image[nr][nc]==ic){
                    ans[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
        
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0] .size();
        int ic= image[sr][sc];
        vector<vector<int>>ans = image;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        bfs(n,m,sr,sc,ans,image,ic,color,dr,dc);
        return ans;
    }
    
};
int countNegatives(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int row =0;
        int col = grid[0].size()-1;
        int count = 0;
        while(row<grid.size() && col>=0){
            if(grid[row][col]<0){
                col--;
                count+=nr-row;
            }
            else{
                row++;
            }
        }
        return count;
    }
class Solution {
public:
int count=0;
   
    void dfs(int row, int col, vector<vector<int>>& grid) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
        count++;
        return; // Count the perimeter for out-of-bound cells and water cells
    }
    if (grid[row][col] == -1) {
        return ; // Cell already visited, don't count its perimeter again
    }
    
    grid[row][col] = -1; // Mark the cell as visited
    // int perimeter = 0;
     dfs(row + 1, col, grid);
   dfs(row - 1, col, grid);
  dfs(row, col + 1, grid);
     dfs(row, col - 1, grid);
  
}

int islandPerimeter(vector<vector<int>>& grid) {
    count=0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j, grid);
            }
        }
    }
    return count; // No island found, return 0 perimeter
}

};


User
int dfs(int row, int col, vector<vector<int>>& grid) {
    if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) {
        return 1; // Count the perimeter for out-of-bound cells and water cells
    }
    if (grid[row][col] == -1) {
        return 0; // Cell already visited, don't count its perimeter again
    }
    
    grid[row][col] = -1; // Mark the cell as visited
    int perimeter = 0;
    perimeter += dfs(row + 1, col, grid);
    perimeter += dfs(row - 1, col, grid);
    perimeter += dfs(row, col + 1, grid);
    perimeter += dfs(row, col - 1, grid);
    return perimeter;
}

int islandPerimeter(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                return dfs(i, j, grid);
            }
        }
    }
    return 0; // No island found, return 0 perimeter
}


class Solution{
public:
    vector<int> downwardDiagonal(int N, vector<vector<int>> A)
    {
        int row = 0;
        int col = 0;
        vector<int> ans;
        while (col < N) {
            int r = row;
            int c = col;
            while (r < N && c >= 0) {
                ans.push_back(A[r][c]);
                r++;
                c--;
            }
            col++;
        }
        row = 1;
        col = N - 1;
        while (row < N) {
            int r = row;
            int c = col;
            while (r < N && c >= 0) {
                ans.push_back(A[r][c]);
                r++;
                c--;
            }
            row++;
        }
        return ans;
    }
};


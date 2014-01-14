class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int w = grid.size();
        int h=  grid[0].size();
        int r[h];
        r[0] = grid[0][0];
        for (int i = 1; i < h; i++) {
            r[i] = r[i-1] + grid[0][i];
        }
        for (int i = 1; i < w; i++) {
            r[0] += grid[i][0];
            for (int j = 1; j < h; j++) {
                r[j] = r[j] > r[j-1] ? r[j-1] : r[j];
                r[j] += grid[i][j];
            }
        }
        return r[h-1];
    }
};

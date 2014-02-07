class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m, n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            obstacleGrid[0][j] = -1;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) break;
            obstacleGrid[i][0] = -1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                if (obstacleGrid[i-1][j] == 1) obstacleGrid[i][j]--;
                if (obstacleGrid[i][j-1] == 1) obstacleGrid[i][j]--;
            }
        }
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        return -obstacleGrid[m - 1][n - 1];
    }
};

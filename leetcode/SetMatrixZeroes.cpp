class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int w = -1, h = -1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    w = i, h = j;
                    break;
                }
            }
            if (w >= 0) {
                break;
            }
        }
        if (w < 0 && h < 0) return;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[w][j] = 0;
                    matrix[i][h] = 0;
                }
            }
        }
        
        for (int i = 0; i < matrix.size(); i++) {
            if (i == w) continue;
            if (matrix[i][h] == 0) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[w][j] == 0) {
                for (int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;
                }
            }
            matrix[w][j] = 0;
        }
    }
};

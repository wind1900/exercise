class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> r;
        if (matrix.size() == 0) return r;
        int h = matrix.size(), w = matrix[0].size();
        int up = 0, down = h - 1, left = 0, right = w - 1;
        int x = 0, y = 0;
        int d = 0;
        for (int i = 0; i < w * h; i++) {
            r.push_back(matrix[y][x]);
            if (d == 0) {
                if (x == right) {
                    up++;
                    y++;
                    d = 1;
                } else {
                    x++;
                }
            } else if (d == 1) {
                if (y == down) {
                    right--;
                    x--;
                    d = 2;
                } else {
                    y++;
                }
            } else if (d == 2) {
                if (x == left) {
                    down--;
                    y--;
                    d = 3;
                } else {
                    x--;
                }
            } else {
                if (y == up) {
                    left++;
                    x++;
                    d = 0;
                } else {
                    y--;
                }
            }
            
        }
        return r;
    }
};

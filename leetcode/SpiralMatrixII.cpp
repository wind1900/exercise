class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int i, j, x = 0, y = n - 1;
        vector<vector<int> > r;
        for (i = 0; i < n; i++) {
            r.push_back(vector<int>(n, 0));
        }
        i = 1;
        while (x <= y) {
            if (x == y) {
                r[x][x] = i;
            }
            else {
                for (j = 0; j < y - x; j++) {
                    r[x][x + j] = i + j;
                    r[x + j][y] = i + j + y - x;
                    r[y][y - j] = i + j + 2 * (y - x);
                    r[y - j][x] = i + j + 3 * (y - x);
                }
            }
            i += 4 * (y - x);
            x++;
            y--;
        }
        return r;
    }
};

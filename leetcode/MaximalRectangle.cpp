class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0) return 0;
        int w = matrix.size(), h = matrix[0].size();
        int m = 0, i, j, left, right;
        vector<int> l(h, 0);
        vector<int> r(h, h-1);
        vector<int> hg(h, 0);
        for (i = 0; i < w; i++) {
            left = 0;
            for (j = 0; j < h; j++) {
                if (matrix[i][j] == '1') {
                    hg[j]++;
                    l[j] = max(l[j], left);
                } else {
                    hg[j] = 0;
                    l[j] = 0;
                    left = j + 1;
                }
            }
            right = h - 1;
            for (j = h - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    r[j] = min(r[j], right);
                } else {
                    r[j] = h - 1;
                    right = j - 1;
                }
                m = max(m, hg[j] * (r[j] - l[j] + 1));
            }
        }
        return m;
    }
};

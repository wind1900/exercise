class Solution {
public:
    int minCut(string s) {
        int i, j, l = s.length();
        vector<vector<bool>> pal(l, vector<bool>(l, false));
        for (i = 0; i < l; i++) {
            pal[i][i] = true;
            for (j = 1; i - j >= 0 && i + j < l; j++) {
                if (s[i-j] == s[i+j]) {
                    pal[i-j][i+j] = true;
                } else {
                    break;
                }
            }
        }
        for (i = 0; i < l - 1; i++) {
            for (j = 0; i - j >= 0 && i + j + 1 < l; j++) {
                if (s[i-j] == s[i+j+1]) {
                    pal[i-j][i+j+1] = true;
                } else {
                    break;
                }
            }
        }
        vector<int> r(l, -1);
        for (i = 0; i < l; i++) {
            if (pal[0][i]) {
                r[i] = 0;
            }
            else {
                r[i] = i;
                for (j = 0; j < i; j++) {
                    if (pal[j+1][i]) {
                        r[i] = min(r[i], r[j] + 1);
                    }
                }
            }
        }
        return r[l-1];
    }
};

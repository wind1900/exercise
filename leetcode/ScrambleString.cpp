class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (s2.length() != n) return false;
        bool ***is = new bool**[n];
        for (int i = 0; i < n; i++) {
            is[i] = new bool*[n];
            for (int j = 0; j < n; j++) {
                is[i][j] = new bool[n];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                is[0][i][j] = (s1[i] == s2[j]);
            }
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n - l + 1; i++) {
                for (int j = 0; j < n - l + 1; j++) {
                    is[l-1][i][j] = false;
                    for (int k = 1; k < l; k++) {
                        if ((is[k-1][i][j] && is[l-k-1][i+k][j+k]) || (is[k-1][i][j+l-k]) && is[l-k-1][i+k][j]) {
                            is[l-1][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return is[n - 1][0][0];
    }
};

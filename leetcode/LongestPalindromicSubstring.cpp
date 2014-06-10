class Solution {
public:
    string longestPalindrome(string s) {
        int i, j, l = s.length(), c = 0, r = 0, p = 0;
        char *b = new char[2 * l + 2];
        vector<int> t(2 * l + 1, 0);
        for (i = 0; i < 2 * l; i++) {
            if ((i & 1) == 0) {
                b[i] = '#';
            } else {
                b[i] = s[i/2];
            }
        }
        b[i] = '#';
        b[i+1] = 0;
        for (i = 0; i + r < 2 * l + 1; i++) {
            j = t[2 * c - i];
            if (j > t[c] - i + c) j = t[c] - i + c;
            for (j += 1; i - j >= 0 && i + j < 2 * l + 1 && b[i-j] == b[i+j]; j++);
            if (--j > r) {
                p = i;
                r = j;
            }
            t[i] = j;
            if (t[i] + i >= t[c] + c) {
                c = i;
            }
        }
        return s.substr(p / 2 - r / 2, r);
    }
};

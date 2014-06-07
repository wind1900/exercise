class Solution {
public:
    int numDecodings(string s) {
        int l = s.size();
        if (l == 0) return 0;
        vector<int> r(l+1, 0);
        r[0] = 1;
        r[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= l; i++) {
            if (s[i-1] != '0') r[i] += r[i - 1];
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7')) r[i] += r[i - 2];
        }
        return r[l];
    }
};

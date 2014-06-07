class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<bool> d(s1.size() + 1, false);
        int i, j;
        for (j = 0; j < s1.size(); j++) {
            if (s1[j] == s3[j]) d[j+1] = true;
            else break;
        }
        d[0] = true;
        for (i = 0; i < s2.size(); i++) {
            if (!d[0] || s3[i] != s2[i]) d[0] = false;
            for (j = 1; j <= s1.size(); j++) {
                if (d[j] && s2[i] == s3[i+j]) d[j] = true;
                else if (d[j-1] && s1[j-1] == s3[i+j]) d[j] = true;
                else d[j] = false;
            }
        }
        return d[s1.size()];
    }
};

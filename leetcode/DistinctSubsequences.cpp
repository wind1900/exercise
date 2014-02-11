class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> p(T.length() + 1, 0);
        p[0] = 1;
        for (int i = 0; i < S.length(); i++) {
            for (int j = min(i + 1, (int) T.length()); j > 0; j--) {
                if (S[i] == T[j - 1]) {
                    p[j] += p[j - 1];
                }
            }
        }
        return p.back();
    }
};

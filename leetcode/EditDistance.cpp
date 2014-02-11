class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> p, q;
        for (int i = 0; i <= word1.length(); i++) {
            p.push_back(i);
        }
        for (int i = 1; i <= word2.length(); i++) {
            q.push_back(i);
            for (int j = 1; j <= word1.length(); j++) {
                int r = max(i, j);
                if (word1[j - 1] == word2[i - 1]) {
                    r = min(r, p[j - 1]);
                } else {
                    r = min(r, p[j] + 1);
                    r = min(r, q[j - 1] + 1);
                    r = min(r, p[j - 1] + 1);
                }
                q.push_back(r);
            }
            p = q;
            q.clear();
        }
        return p.back();
    }
};

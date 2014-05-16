class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        bool *r = new bool[s.length()+1];
        r[s.length()] = true;
        for (int i = s.length() - 1; i >= 0; i--) {
            r[i] = false;
            for (int j = s.length(); j > i; j--) {
                if (r[j] && dict.count(s.substr(i, j - i)) > 0) {
                    r[i] = true;
                    break;
                }
            }
        }
        return r[0];
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int i, j, l = s.size();
        vector<vector<int>> t(l, vector<int>());
        string ss;
        for (i = l - 1; i >= 0; i--) {
            for (j = i; j < l; j++) {
                ss = s.substr(i, j - i + 1);
                if (dict.count(ss) > 0 && (j == l - 1 || t[j + 1].size() > 0)) {
                    t[i].push_back(j);
                }
            }
        }
        ss = "";
        vector<string> r;
        search(t, r, ss, 0, s);
        return r;
    }
    
    void search(vector<vector<int>> &t, vector<string> &r, string s, int i, string &o) {
        if (i == t.size()) {
            r.push_back(s);
            return;
        }
        string ss, tt;
        for (int j : t[i]) {
            ss = o.substr(i, j - i + 1);
            if (s.size() == 0) tt = ss;
            else tt = s + " " + ss;
            search(t, r, tt, j + 1, o);
        }
    }
};

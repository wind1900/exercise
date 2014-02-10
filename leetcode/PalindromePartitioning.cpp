class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> r;
        vector<string> t;
        partition(r, t, s, 0);
        return r;
    }
    
    void partition(vector<vector<string>> &r, vector<string> &t, string s, int i) {
        if (i == s.size()) {
            r.push_back(t);
        }
        for (int j = i; j < s.size(); j++) {
            if (isP(s, i, j)) {
                t.push_back(s.substr(i, j - i + 1));
                partition(r, t, s, j + 1);
                t.pop_back();
            }
        }
    }
    
    bool isP(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

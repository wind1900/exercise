class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        if (n == 0) return v;
        r(v, n, 0, 0, "");
        return v;
    }
    
    void r(vector<string> &v, int n, int lp, int rp, string s) {
        if (rp == n) {
            v.push_back(s);
            return;
        }
        if (lp > rp) r(v, n, lp, rp+1, s+")");
        if (lp < n) r(v, n, lp+1, rp, s+"(");
    }
};

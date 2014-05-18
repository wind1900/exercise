class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> r;
        vector<string> t;
        search(r, t, 0, s);
        return r;
    }
    
    void search(vector<string> &r, vector<string> &t, int st, string &s) {
        if (t.size() == 4) {
            if (st == s.size()) {
                string su = t[0]+"."+t[1]+"."+t[2]+"."+t[3];
                r.push_back(su);
            }
            return;
        }
        if (st >= s.size()) return;
        string sub;
        int n;
        for (int i = 1; i <= 3; i++) {
            sub = s.substr(st, i);
            n = atoi(sub.c_str());
            if ((n != 0 && sub[0] == '0') || (n == 0 && i > 1)) continue;
            if (n <= 255) {
                t.push_back(sub);
                search(r, t, st + i, s);
                t.pop_back();
            }
        }
    }
};

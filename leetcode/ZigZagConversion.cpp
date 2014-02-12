class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s;
        stringstream ss;
        vector<string> t(nRows, "");
        int d = 1, r = 0;;
        for (int i = 0; i < s.length(); i++) {
            if (r == 0) {
                d = 1;
            } else if (r == nRows - 1) {
                d = -1;
            }
            t[r].push_back(s[i]);
            r += d;
        }
        for (auto i : t) {
            ss << i;
        }
        return ss.str();
    }
};

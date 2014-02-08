class Solution {
public:
    string countAndSay(int n) {
        string r = "1";
        int i, j;
        while (--n) {
            stringstream ss;
            for (i = 0; i < r.size();) {
                for (j = i + 1; j < r.size() && r[j] == r[i]; j++);
                ss << (j - i) << r[i];
                i = j;
            }
            r = ss.str();
        }
        return r;
    }
};

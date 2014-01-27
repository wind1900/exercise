class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > r;
        vector<int> c;
        combine(r, c, 0, n, k);
        return r;
    }
    
    void combine(vector<vector<int> > &r, vector<int> &c, int s, int n, int k) {
        if (n - s < k) return;
        if (k == 0) {
            r.push_back(c);
            return;
        } else {
            for (int i = s + 1; i <= n; i++) {
                c.push_back(i);
                combine(r, c, i, n, k-1);
                c.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > r;
        for (int i = 0; i < (1 << S.size()); i++) {
            vector<int> t;
            for (int j = 0; j < S.size(); j++) {
                if (i & (1 << j)) {
                    t.push_back(S[j]);
                }
            }
            r.push_back(t);
        }
        return r;
    }
};

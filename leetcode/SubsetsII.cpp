class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int>> r;
        if (S.size())
            r.push_back(vector<int>());
        for (int i = 0; i < S.size();) {
            int j;
            for (j = i + 1; j < S.size() && S[j] == S[i]; j++);
            int size = r.size();
            for (int k = 0; k < size; k++) {
                vector<int> t = r[k];
                for (int l = i; l < j; l++) {
                    t.push_back(S[i]);
                    r.push_back(t);
                }
            }
            i = j;
        }
        return r;
    }
};

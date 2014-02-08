class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > r;
        vector<int> t;
        if (candidates.size() == 0) return r;
        s(r, candidates, t, 0, 0, target);
        return r;
    }
    
    void s(vector<vector<int> > &r, vector<int> &cand, vector<int> &t, int p, int sum, int target) {
        if (sum == target) {
            r.push_back(t);
            return;
        } else if (sum > target || p == cand.size()) {
            return;
        } else {
            s(r, cand, t, p + 1, sum, target);
            for (int i = 1; sum + i * cand[p] <= target; i++) {
                t.push_back(cand[p]);
                s(r, cand, t, p + 1, sum + i * cand[p], target);
            }
            while (!t.empty() && t.back() == cand[p]) {
                t.pop_back();
            }
        }
    }
};

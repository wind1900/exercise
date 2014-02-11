class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<vector<int> > r;
        vector<int> t;
        cs(r, t, num, 0, 0, target);
        return r;
    }
    
    void cs(vector<vector<int>> &r, vector<int> &t, vector<int> &num, int s, int sum, int target) {
        if (sum == target) {
            r.push_back(t);
            return;
        }
        if (sum > target || s == num.size()) {
            return;
        }
        int c = 1;
        int j = s + 1;
        while (j < num.size() && num[j] == num[s]) j++;
        cs(r, t, num, j, sum, target);
        for (int i = 1; i <= j - s; i++) {
            t.push_back(num[s]);
            cs(r, t, num, j, sum + i * num[s], target);
        }
        while (!t.empty() && t.back() == num[s]) t.pop_back();
    }
};

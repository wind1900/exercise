class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> r;
        permute(r, num, 0);
        return r;
    }
    
    void permute(vector<vector<int>> &r, vector<int> &num, int i) {
        if (i >= num.size() - 1) {
            r.push_back(num);
            return;
        }
        for (int j = i; j < num.size(); j++) {
            swap(num[i], num[j]);
            permute(r, num, i + 1);
            swap(num[i], num[j]);
        }
    }
};
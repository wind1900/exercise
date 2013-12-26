class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r;
        if (numRows == 0) return r;
        r.push_back(vector<int>(1,1));
        for (int i = 2; i <= numRows; i++) {
            vector<int> &p = r.back();
            vector<int> row(i,1);
            for (int j = 1; j < i - 1; j++) {
                row[j] = (p[j - 1] + p[j]);
            }
            r.push_back(row);
        }
        return r;
    }
};
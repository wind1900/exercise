class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> p;
        p.push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            p.push_back(triangle[i][i] + p[i - 1]);
            for (int j = i - 1; j > 0; j--) {
                p[j] = min(p[j], p[j - 1]) + triangle[i][j];
            }
            p[0] += triangle[i][0];
        }
        return *min_element(p.begin(), p.end());
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
        int x;
        for (int i = 0; i < (1<<n); i++) {
            r.push_back(i ^ (i >> 1));
        }
        return r;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r(rowIndex+1, 0);
        r[0] = 1;
        for (int i = 0; i < rowIndex; i++) {
            for (int j = i + 1; j > 0; j--) {
                r[j] += r[j - 1];
            }
            r[0] = 1;
        }
        return r;
    }
};

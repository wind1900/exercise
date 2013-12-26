class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int r = 0;
        int m = INT_MAX;
        for (int p : prices) {
            m = p < m ? p : m;
            r = r > (p - m) ? r : (p - m);
        }
        return r;
    }
};
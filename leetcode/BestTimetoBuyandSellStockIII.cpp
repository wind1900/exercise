class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0) return 0;
        vector<int> l(prices.size(), 0), r(prices.size(), 0);
        int p = prices[0], m = 0;
        for (int i = 1; i < prices.size(); i++) {
            p = min(p, prices[i]);
            l[i] = max(l[i - 1], prices[i] - p);
        }
        p = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            p = max(p, prices[i]);
            r[i] = max(r[i + 1], p - prices[i]);
        }
        for (int i = 0; i < prices.size(); i++) {
            m = max(m, l[i] + r[i]);
        }
        return m;
    }
};

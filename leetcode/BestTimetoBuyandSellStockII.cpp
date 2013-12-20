class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int p = 0;
        int s = prices.size();
        int i = 0;
        while (i < s) {
            int low = prices[i++];
            while (i < s && prices[i] < low) {
                low = prices[i++];
            }
            if (i == s) break;
            int high = prices[i++];
            while (i < s && prices[i] > high) {
                high = prices[i++];
            }
            p += high - low;
        }
        return p;
    }
};
class Solution {
public:
    int numTrees(int n) {
        int r = 1, d = 1, m = 2 * n;
        while (d <= n) {
            r *= m--;
            r /= d++;
        }
        return r/(n+1);
    }
};
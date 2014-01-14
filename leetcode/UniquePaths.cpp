class Solution {
public:
    int uniquePaths(int m, int n) {
        int mm = m < n ? m : n;
        long long r = 1;
        for (int i = 1; i < mm; i++) {
            r *= (m + n - i - 1);
            r /= i;
        }
        return r;
    }
};

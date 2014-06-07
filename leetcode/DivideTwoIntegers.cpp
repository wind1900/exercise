class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d = divisor;
        long long div = dividend;
        if (d < 0) d = -d;
        if (div < 0) div = -div;
        int p = 0, r = 0;
        bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
        while (d < div) {
            d = d << 1;
            p++;
        }
        while (p >= 0) {
            if (div >= d) {
                div -= d;
                r += 1 << p;
            }
            p--;
            d = d >> 1;
        }
        if (neg) r = -r;
        return r;
    }
};

class Solution {
public:
    double pow(double x, int n) {
        if (x == 1) return 1;
        double r = 1;
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        while (n) {
            if (n & 1) {
                r *= x;
            }
            x = x * x;
            n = n / 2;
        }
        return r;
    }
};

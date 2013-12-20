class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while (x) {
            r *= 10;
            r += x % 10;
            x /= 10;
        }
        return r;
    }
};
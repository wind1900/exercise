class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 0, c = 1;
        while (n--) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
};
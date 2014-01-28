class Solution {
public:
    bool isPalindrome(int x) {
        int j = 1, a, b;
        long long i = 1;
        if (x < 0) return false;
        while (x / i >= 10) {
            i *= 10;
        }
        while (i > j) {
            a = (x % (i * 10)) / i;
            b = (x % (j * 10)) / j;
            if (a != b) return false;
            i /= 10;
            j *= 10;
        }
        return true;
    }
};

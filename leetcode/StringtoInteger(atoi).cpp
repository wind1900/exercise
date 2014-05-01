class Solution {
public:
    int atoi(const char *str) {
        while (*str == ' ') str++;
        bool neg = false;
        int r = 0, t;
        if (*str == '+') str++;
        else if (*str == '-') {
            neg = true;
            str++;
        }
        while (*str) {
            if (*str >= '0' && *str <= '9') {
                t = 10 * r + (*str-'0');
                if (neg) {
                    if (-t / 10 != -r) return INT_MIN;
                } else {
                    if (t / 10 != r) return INT_MAX;
                }
                r = t;
            }
            else {
                if (neg) r = -r;
                return r;
            }
            str++;
        }
        if (neg) r = -r;
        return r;
    }
};

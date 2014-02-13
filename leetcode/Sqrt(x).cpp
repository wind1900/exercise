class Solution {
public:
    int sqrt(int x) {
        if (!x) return 0;
        int begin = 1, end = x, mid, r;
        while (begin <= end) {
            mid = (end - begin) / 2 + begin;
            if (x / mid == mid) return mid;
            else if (x / mid > mid) {
                r = mid;
                begin = mid + 1;
            }
            else end = mid - 1;
        }
        return r;
    }
};

class Solution {
public:
    int trap(int A[], int n) {
        int maxi = 0, max;
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > A[maxi]) {
                maxi = i;
            }
        }
        max = 0;
        for (int i = 0; i < maxi; i++) {
            if (A[i] > max) {
                max = A[i];
            } else {
                r += max - A[i];
            }
        }
        max = 0;
        for (int i = n - 1; i > maxi; i--) {
            if (A[i] > max) {
                max = A[i];
            } else {
                r += max - A[i];
            }
        }
        return r;
    }
};

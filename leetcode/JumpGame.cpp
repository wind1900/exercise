class Solution {
public:
    bool canJump(int A[], int n) {
        int r = 0;
        for (int i = 0; i <= r && r < n - 1; i++) {
            r = max(r, i + A[i]);
        }
        return r >= n - 1;
    }
};
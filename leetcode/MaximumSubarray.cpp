class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max = A[0], cur = A[0];
        for (int i = 1; i < n; i++) {
            cur = A[i] > (cur + A[i]) ? A[i] : (cur + A[i]);
            max = max > cur ? max : cur;
        }
        return max;
    }
};
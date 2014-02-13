class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            if (A[i] > 0 && A[i] <= n) {
                int t = A[i];
                if (A[t - 1] == t) continue;
                A[i] = A[t - 1];
                A[t - 1] = t;
                i--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

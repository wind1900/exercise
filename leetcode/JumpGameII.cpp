class Solution {
public:
    int jump(int A[], int n) {
        int i = 0, j = 0, ii, jj;
        int r = 0;
        while (j < n - 1) {
            ii = j + 1;
            jj = j + 1;
            for (int k = i; k <= j; k++) {
                jj = max(jj, k + A[k]);
            }
            r++;
            i = ii;
            j = jj;
        }
        return r;
    }
};

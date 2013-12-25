class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m + n;
        while (m && n) {
            if (A[m - 1] > B[n - 1]) A[--i] = A[--m];
            else A[--i] = B[--n];
        }
        while (n) {
            A[--i] = B[--n];
        }
    }
};
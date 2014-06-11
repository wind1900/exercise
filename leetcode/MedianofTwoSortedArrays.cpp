class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m > n) return findMedianSortedArrays(B, n, A, m);
        int am = m / 2, bm = n / 2, k;
        if (m == 0) {
            if (n % 2 == 0) return (B[bm] + B[bm - 1]) / 2.0;
            return B[bm];
        } else if (m == 1 && n == 1) {
            return (A[0] + B[0]) / 2.0;
        } else if (m == 2 && n == 2) {
            return (max(A[0], B[0]) + min(A[1], B[1])) / 2.0;
        }
        if ((m % 2) == 0 && (n % 2) == 0) {
            bm--;
        }
        if (A[am] == B[bm]) return A[am];
        else if (A[am] < B[bm]) {
            k = min(am, n - bm - 1);
            if (k == 0) {
                if (A[am] <= B[bm - 1]) {
                    return findMedianSortedArrays(A + 1, 0, B, n - 1);
                } else {
                    if (n % 2 == 0) return A[am];
                    return (A[am] + B[bm]) / 2.0;
                }
            }
            return findMedianSortedArrays(A + k, m - k, B, n - k);
        } else {
            k = min(m - am - 1, bm);
            if (k == 0) {
                if (m == 1 && (n % 2) == 1) {
                    if (A[am] <= B[bm + 1]) {
                        return (A[am] + B[bm]) / 2.0;
                    }
                }
                if (m == 2 && (n % 2) == 0) {
                    if (A[am] <= B[bm + 1]) {
                        return findMedianSortedArrays(A, m, B + 1, n - 2);
                    }
                }
                return findMedianSortedArrays(A, m - 1, B + 1, n - 1);
            }
            return findMedianSortedArrays(A, m - k, B + k, n - k);
        }
    }
};

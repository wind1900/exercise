class Solution {
public:
    void sortColors(int A[], int n) {
        int i = 0, j = n - 1, l = 0;
        while (i <= j) {
            if (A[i] == 2) {
                A[i] = A[j];
                A[j--] = 2;
            } else if (A[i] == 1) {
                i++;
            } else {
                A[i++] = A[l];
                A[l++] = 0;
            }
        }
    }
};

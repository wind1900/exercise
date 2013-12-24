class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int l = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[l++] = A[i];
            }
        }
        return l;
    }
};
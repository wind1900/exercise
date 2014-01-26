class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0, j = 0;
        while (j < n) {
            A[i++] = A[j++];
            if (j < n && A[i - 1] == A[j]) {
                A[i++] = A[j++];
                while (j < n && A[i - 1] == A[j]) j++;
            }
        }
        return i;
    }
};

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0, l = 0;
        while (i < n) {
            A[l] = A[i++];
            while (i < n && A[l] == A[i]) i++;
            l++;
        }
        return l;
    }
};
class Solution {
public:
    bool search(int A[], int n, int target) {
        int begin = 0, end = n - 1;
        int mid;
        while (begin <= end) {
            mid = (end - begin) / 2 + begin;
            if (A[mid] == target) return true;
            if (A[begin] == A[end]) {
                end--;
                continue;
            }
            if (A[mid] >= A[begin]) {
                if (target < A[mid] && target >= A[begin]) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else {
                if (target > A[mid] && target <= A[end]) {
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};

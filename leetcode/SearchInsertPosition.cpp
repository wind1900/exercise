class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int begin = 0;
        int end = n - 1;
        int mid;
        while (begin <= end) {
            mid = (end - begin) / 2 + begin;
            if (A[mid] == target) return mid;
            else if (A[mid] < target) begin = mid + 1;
            else end = mid - 1;
        }
        return begin;
    }
};
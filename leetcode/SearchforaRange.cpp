class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> r(2, -1);
        int begin = 0, end = n - 1;
        int mid;
        while (begin <= end) {
            mid = (end - begin) / 2 + begin;
            if (A[mid] > target) end = mid - 1;
            else if (A[mid] < target) begin = mid + 1;
            else {
                if (mid == 0 || A[mid - 1] < target) {
                    r[0] = mid;
                    break;
                } else {
                    end = mid - 1;
                }
            }
        }
        begin = 0;
        end = n - 1;
        while (begin <= end) {
            mid = (end - begin) / 2 + begin;
            if (A[mid] > target) end = mid - 1;
            else if (A[mid] < target) begin = mid + 1;
            else {
                if (mid == n - 1 || A[mid + 1] > target) {
                    r[1] = mid;
                    break;
                } else {
                    begin = mid + 1;
                }
            }
        }
        return r;
    }
};

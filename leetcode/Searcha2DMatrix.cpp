class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int begin = 0, end = matrix.size() - 1;
        int mid, mid1;
        while (begin <= end) {
            mid = (end - begin) / 2 + begin;
            if (matrix[mid].front() <= target && target <= matrix[mid].back()) break;
            else if (target < matrix[mid].front()) end = mid - 1;
            else begin = mid + 1;
        }
        if (begin <= end) {
            begin = 0;
            end = matrix[mid].size() - 1;
            while (begin <= end) {
                mid1 = (end - begin) / 2 + begin;
                if (matrix[mid][mid1] == target) return true;
                else if (target < matrix[mid][mid1]) end = mid1 - 1;
                else begin = mid1 + 1;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> sorted(numbers);
        std::sort(sorted.begin(), sorted.end());
        vector<int> result;
        int i = 0, j = numbers.size()-1;
        while (i < j) {
            if (sorted[i] + sorted[j] > target)
                j--;
            else if (sorted[i] + sorted[j] < target)
                i++;
            else
                break;
        }
        for (int k = 0; i >= 0 || j >= 0; k++) {
            if (i >= 0 && numbers[k] == sorted[i]) {
                result.push_back(k+1);
                i = -1;
            } else if(j >= 0 && numbers[k] == sorted[j]) {
                result.push_back(k+1);
                j = -1;
            }
            
        }
        return result;
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits.insert(digits.begin(), 0);
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            digits[i]++;
            if (digits[i] >= 10) {
                digits[i] = 0;
            } else {
                break;
            }
        }
        if (digits[0] == 0) {
            digits.erase(digits.begin());
        }
        return digits;
    }
};

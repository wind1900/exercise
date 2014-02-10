class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i, j;
        for (i = num.size() - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) break;
        }
        if (i >= 0) {
            for (j = i + 1; j < num.size() && num[j] > num[i]; j++);
            j--;
            num[i] ^= num[j];
            num[j] ^= num[i];
            num[i] ^= num[j];
        }
        for (++i, j = num.size() - 1; i < j; i++, j--) {
            num[i] ^= num[j];
            num[j] ^= num[i];
            num[i] ^= num[j];
        }
    }
};

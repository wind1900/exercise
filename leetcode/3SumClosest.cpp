class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int begin, end, sum, r = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size() - 2 && num[i] <= target / 3; i++) {
            begin = i + 1;
            end = num.size() - 1;
            while (begin < end) {
                sum = num[i] + num[begin] + num[end];
                if (sum == target) return target;
                else if (sum < target) {
                    if (abs(sum - target) < abs(r - target)) {
                        r = sum;
                    }
                    begin++;
                } else {
                    if (abs(sum - target) < abs(r - target)) {
                        r = sum;
                    }
                    end--;
                }
            }
        }
        return r;
    }
};

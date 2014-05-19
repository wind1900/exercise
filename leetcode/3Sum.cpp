class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> r;
        sort(num.begin(), num.end());
        int begin, end, s;
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            begin = i + 1;
            end = num.size() - 1;
            while (begin < end) {
                s = num[i] + num[begin] + num[end];
                if (s == 0) {
                    r.push_back(vector<int>{num[i], num[begin], num[end]});
                    begin++;
                    while (begin < end && num[begin] == num[begin-1])
                        begin++;
                } else if (s > 0) {
                    end--;
                } else if (s < 0) {
                    begin++;
                }
            }
        }
        return r;
    }
};

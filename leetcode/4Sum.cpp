class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        if (num.size() < 4) return vector<vector<int> >();
        set<vector<int> > r;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; i++) {
            for (int j = i + 1; j < num.size() - 2; j++) {
                set<pair<int, int> > s = twoSum(num, j + 1, target - num[i] - num[j]);
                if (s.size()) {
                    for (auto p : s) {
                        vector<int> v;
                        v.push_back(num[i]);
                        v.push_back(num[j]);
                        v.push_back(p.first);
                        v.push_back(p.second);
                        r.insert(v);
                    }
                }
            }
        }
        return vector<vector<int> >(r.begin(), r.end());
    }
    
    set<pair<int, int> > twoSum(vector<int> &num, int begin, int target) {
        int end = num.size() - 1;
        set<pair<int, int> > r;
        while (begin < end) {
            if (target == num[begin] + num[end]) {
                pair<int, int> p(num[begin], num[end]);
                r.insert(p);
                begin++;
            } else if (target < num[begin] + num[end]) {
                end--;
            } else {
                begin++;
            }
        }
        return r;
    }
};

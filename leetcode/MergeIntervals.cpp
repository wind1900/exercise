/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<pair<int, int>> t;
        vector<Interval> r;
        int left, c = 0;
        for (Interval i : intervals) {
            t.push_back(make_pair(i.start, -1));
            t.push_back(make_pair(i.end, 1));
        }
        sort(t.begin(), t.end());
        for (pair<int, int> p : t) {
            if (c == 0) left = p.first;
            c += p.second;
            if (c == 0) r.push_back(Interval(left, p.first));
        }
        return r;
    }
};

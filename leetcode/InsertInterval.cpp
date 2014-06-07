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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int left = newInterval.start, right = newInterval.end, i = 0;
        vector<Interval> r;
        while (i < intervals.size() && intervals[i].end < left) {
            r.push_back(intervals[i++]);
        }
        while (i < intervals.size() && intervals[i].start <= right) {
            left = min(left, intervals[i].start);
            right = max(right, intervals[i].end);
            i++;
        }
        r.push_back(Interval(left, right));
        while (i < intervals.size()) {
            r.push_back(intervals[i++]);
        }
        return r;
    }
};

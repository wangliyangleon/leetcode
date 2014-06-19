// https://oj.leetcode.com/problems/merge-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static bool operator<(const Interval &x, const Interval &y)
{
    if (x.start == y.start) {
        return x.end < y.end;
    } else {
        return x.start < y.start;
    }
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<Interval> result;
        for (vector<Interval>::const_iterator iter = intervals.begin();
                iter != intervals.end(); ++iter) {
            size_t cur_size = result.size();
            if (0 == cur_size) {
                result.push_back(*iter);
            } else {
                if (iter->start <= result.at(cur_size - 1).end) {
                    result.at(cur_size - 1).end = max(iter->end, result.at(cur_size - 1).end);
                } else {
                    result.push_back(*iter);
                }
            }
        }
        return result;
    }
};

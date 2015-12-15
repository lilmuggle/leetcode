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
    vector<Interval> mergeIntervals(vector<Interval>& intervals) {
        vector<Interval> res;
        Interval pre = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(pre.end < intervals[i].start) {
                res.push_back(pre);
                pre = intervals[i];
            }
            else
                pre.end = max(pre.end, intervals[i].end);
        }
        res.push_back(pre);
        return res;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i = 0;
        while(i < intervals.size() && intervals[i].start < newInterval.start) {
            i++;
        }
        if(i == intervals.size())
            intervals.push_back(newInterval);
        else
            intervals.insert(intervals.begin() + i, newInterval);
        return mergeIntervals(intervals);
    }
};

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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if(intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.end < b.end;});
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
};

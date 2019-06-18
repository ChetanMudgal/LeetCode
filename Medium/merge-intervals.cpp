// https://www.interviewbit.com/problems/merge-intervals/
// Google, Medium
// O(nlogn)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b) {
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    intervals.push_back(newInterval);
    
    vector<Interval>result;
    
    sort(intervals.begin(), intervals.end(), compare);
    
    result.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++) {
        if(result[result.size()-1].end >= intervals[i].start) {
            result[result.size()-1].end = max(result[result.size()-1].end, intervals[i].end);
        }
        else {
            result.push_back(intervals[i]);
        }
    }
    
    return result;
}


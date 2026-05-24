/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval &a, Interval &b){
        if (a.end == b.end){
            return a.start < b.start;
        }
        return a.end < b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort in increasing order of end time
        int n = intervals.size();
        if(n==0 || n==1){
            return true;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        // for(auto a: intervals){
        //     cout << a.start << " "<< a.end<< endl;
        // }
        int last_end_time = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            int start_time = intervals[i].start;
            if(start_time<last_end_time){
                return false;
            }
            last_end_time = intervals[i].end;
        }
        return true;
    }
};

class Solution {
public:
    static bool comp(const Interval& a , const Interval& b){
        return a.end < b.end;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),comp);
        for(int i=1;i<n;i++){
            if(intervals[i].start<intervals[i-1].end){
                return false;
            }
        }
        return true;
    }
};

TC - O(nlogn)
SC - O(1)
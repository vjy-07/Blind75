class Solution {
public:
    static bool comp(vector<int>& a , vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count=1;
        sort(intervals.begin(),intervals.end(), comp);
        int lastEndIdx = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>= lastEndIdx){
                count++;
                lastEndIdx = intervals[i][1];
            }
        }
        return n-count;
    }
};

TC - O(nlogn)
SC - O(1)
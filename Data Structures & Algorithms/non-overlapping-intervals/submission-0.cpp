class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){
            return a[0] < b[0];});//introsort o(nlogn)
        // vector<vector<int>> result;
        int prevEnd = intervals[0][1];
        int total = 0;
        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals [i][1];
            if (start >= prevEnd){
                prevEnd = end;
            }
            else{
                total ++;
                prevEnd = min(end, prevEnd);
            }
        }
        return total;
    }
};

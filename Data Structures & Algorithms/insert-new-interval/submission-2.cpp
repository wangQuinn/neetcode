class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result; 
        int i = 0;
        for(; i < intervals.size(); i++){
            if(newInterval[0] > intervals[i][1]){
                result.push_back(intervals[i]); continue;
            }
            //overlapping
            int start = newInterval[0];
            if(intervals[i][0] < newInterval[0]){
                start = intervals[i][0];
            }
            
            int end = newInterval[1];
            while(i < intervals.size() && newInterval[1] >= intervals[i][0]){
                if(intervals[i][1] > end) {
                    end = intervals[i][1];
                }
                i++; 
            }
            
            result.push_back({start, end});
            while (i < intervals.size()){
                result.push_back(intervals[i]);
                i++;
            }
            break; 
        }
    
        if (result.empty() || result.back()[1] < newInterval[0]) {
            result.push_back(newInterval);
        }

        return result; 
    }
};

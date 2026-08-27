// Time Complexity : O(nlogn)
// Space Complexity : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort, detect, merge
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){ return a[0] < b[0];}); //uses introsort nlogn
        vector<vector<int>> result;
        for(int i = 0; i < intervals.size();i++){
            vector<int> temp = intervals[i];
            while(i < intervals.size() && temp[1] >= intervals[i][0]){
                temp[1] = max(temp[1], intervals[i][1]);
                i++;
            }
            i--;
            result.push_back(temp);
        }
        return result;

    }
};
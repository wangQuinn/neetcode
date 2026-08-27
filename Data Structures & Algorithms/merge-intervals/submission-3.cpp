// Time Complexity : O(nlogn)
// because an insertion into map is O(logn) 
// and we loop through, so O(nlogn)
// Space Complexity : O(n)
#include <map>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> counts; //map because sorted
        for(const auto & interval:intervals){
            counts[interval[0]] ++;
            counts[interval[1]] --;
        }
        vector<vector<int>> result;
        vector<int> current;
        int x = 0;
        for(const auto & [i, count] : counts){
            if(current.empty()){
                current.push_back(i);
            }
            x += count;
            if(x == 0){
                current.push_back(i);
                result.push_back(current);
                current.clear();
            }
        }

        return result;

    }
};
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

// sort them. 
// check for OVERLAPPING INTERVALS. 

#include <algorithm> 
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // do i remember my sorts? nah let sjust use the pre built in one. 
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval&b){
            return a.start< b.start;
        }); //i think it uses quick sort so then this would be O(nlogn)
        for(int i = 0; i + 1 < intervals.size(); i++){
            if(intervals[i].end > intervals[i+1].start){
                return false;
            }
        }
        return true;
    }
};

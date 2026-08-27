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
#include <map> 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> x;
        for(const auto& interval : intervals){
            x[interval.start] ++;
            x[interval.end] --;
        }
        int numRooms= 0;
        int have = 0;
        for(const auto& [i, count]: x){
            have += count;
            numRooms = max(numRooms, have);
        }
        return numRooms;
    }
};

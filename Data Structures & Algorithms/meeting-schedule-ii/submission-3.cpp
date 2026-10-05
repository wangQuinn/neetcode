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

#include <queue> 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //minimum number of rooms is maximum number of overlaps

        //first sort the intervals 
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval&b){
            return a.start < b.start;
        });

        //find how many overlapping. 
        priority_queue<int, vector<int>, greater<int>> pq; //greater to make it a min heap. //will store the end times. 
        
        //loop through the code
        
        
        int maximumRooms = 0;
        for(Interval current: intervals){
            //remove expired intervals 
            while(!pq.empty() && pq.top() <= current.start){
                //strictly smaller than because open intervals. 
                //end time is smaller than the start time-> not overlapping
                pq.pop();
            }
            pq.push(current.end);
            //check maximum
            if(pq.size() > maximumRooms){
                maximumRooms = max(maximumRooms, static_cast<int>(pq.size()));
            }
        }

        return maximumRooms;
    }
};

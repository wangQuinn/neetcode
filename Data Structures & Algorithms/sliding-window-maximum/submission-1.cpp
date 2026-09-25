#include <queue>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //have max of the window intially, record the max, 
        // slide the window by 1, and then check if the one we have is greater 
        // or smaller than then max value we have
        //keep the index too. 
        //if greater, update the max, if it's smaller, do not update the max. 

        //yknow what will store it, the maxHeap.

        priority_queue<pair<int, int>> maxi; //stores, maxValue / index, 

        //inital;
        int left = 0;
        vector<int> result;
        for(int right = 0; right < nums.size(); right++){
            //push inital window
            if((right - left + 1) < k){
                maxi.push({nums[right], right});
                //cout << "here i am" <<endl;
                continue;
            }
            else
                maxi.push({nums[right], right});

            while(!maxi.empty() && maxi.top().second < left){
                //cout << "here i am" <<endl;
                maxi.pop(); //remove all of them that are not in the index. 
            }
            result.push_back(maxi.top().first);

             
            left ++; // to move the window up as well. 
        }
        return result;
    }
};

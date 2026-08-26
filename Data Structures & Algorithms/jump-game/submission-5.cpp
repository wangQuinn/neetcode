// Main Takeaways: 
// if it's a true and false you don't have to calculate for the total number of paths to save memory. 
// it's always easier to start from the back and set the last value as true for dp esque problems 
// - greedy algorithms are a subset of dp problems 

// Time Complexity: O(n^2)
// Space Complexity : O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> path;
        path.resize(nums.size(), 0);
        path[nums.size()-1] = 1; //since the last one can always reach
        for(int j = nums.size()-2; j > -1; j--){
            for(int i = 1; i +j < nums.size() && i <= nums[j]; i++){
                if(path[i + j]){
                    path[j] = 1; break;
                }
            }
        }
        return path[0];

    }
};

//greedy solution (time complexity :O(n), space complexity of O(1))

// bool canJump(vector<int>& nums) {
//         int goalIndex = nums.size()-1;
//         for(int i = nums.size()-2; i > -1; i--){
//             if( i + nums[i] >= goalIndex){
//                 goal = i;
//             }
//         }
//         return goal == 0;
//     }
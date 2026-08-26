

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

// let n be the length of nums
//Time Complexity : O(n) 
//Space Complexity : O(1) (uses only two variables)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0]; //guaranteed to have at least one element . 
        int currentSum = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            //for each, choose to include or to not include;
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(currentSum, maxSum);
        }
        return maxSum;

    }
};

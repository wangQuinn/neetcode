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

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxProduct(nums.size() + 1);
        vector<int> minProduct(nums.size() + 1);

        maxProduct[0] = 1;
        if(nums.size() == 1) return nums[0];
        maxProduct[1] = nums[0];
        minProduct[1] = nums[0];
        //we will also need a minimum? 
        //for things like [-4,-3] 
        // max = [1,-4, 12]
        // min = [1, -4, -3]
        // overllMax = 12
        int overallMax = 0;
        for(int i = 2; i < nums.size() + 1;i++){
            maxProduct[i] = max(nums[i - 1] * maxProduct[i-1], max(nums[i-1], nums[i-1] * minProduct[i-1]));
            minProduct[i] = min(nums[i - 1] * maxProduct[i-1], min(nums[i-1], nums[i-1] * minProduct[i-1]));
            overallMax = max(overallMax, max( maxProduct[i], minProduct[i]));
        }

        return overallMax;
    }
};

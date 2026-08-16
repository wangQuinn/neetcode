class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> results;
        vector<int> current;
        recur(nums, results, 0, current);
        return results;
    }
    void recur(vector<int> & nums, vector<vector<int>> & results, int index, vector<int>& currentNums){
        if(index >= nums.size()){
            results.push_back(currentNums); return;
        }
       
        //choose to use
        currentNums.push_back(nums[index]);
        recur(nums, results, index + 1, currentNums);
        //choose not to use. 
        currentNums.pop_back();
        recur(nums, results, index + 1, currentNums);
        
    }
};

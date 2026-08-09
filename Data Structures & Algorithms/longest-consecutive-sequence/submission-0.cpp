#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        for(int i= 0; i < nums.size(); i ++){
            hashTable[nums[i]] = nums[i];
        }

        int maxlength = 0;
        for(int i =0; i < nums.size(); i++){
            if(hashTable.contains(nums[i] - 1)){
                continue;
            }
            
            int length = 0;
            int searchKey = nums[i];
            //else it's the start
            while(hashTable.contains(searchKey)){
                length ++;
                searchKey ++;
            }
            if(length > maxlength){
                maxlength = length;
            }
        }
        return maxlength;
    }
};

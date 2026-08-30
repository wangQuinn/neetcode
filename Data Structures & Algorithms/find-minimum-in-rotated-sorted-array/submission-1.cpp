//time complexity: O(logn) 
//space complexity: O(1)
class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int mid = (l + r) /2;
            if(nums[mid] > nums[r]){ 
            // this mean the turning point is somewhere inbetween mid and r
                l = mid + 1; // l = 2,l = 3 //remember that one of these have to be an off by one to account for it always staying there 
            }
            else{ //nums[mid] < nums[l] 
            //this means the turning point is somewhere inebtewen l and mid. 
                r = mid;// r = 4
            }
        } //this will quit when l == r
        return nums[r];
    }
};
//3,4,5,6,1,2
// mid = 3 -> 6, r -> 2. 6 > 2 -> l = 3. 
// mid = 4 -> 1, 1 < 2, r = 4. 
// l == r return nums[4] -> 1;

//1,2,3,4,5,6
// mid = 2 nums[2] = 3
// 3 !> 6
// r = 2. 
// l = 0, r = 2. mid = 1, nums[1] = 2, 2 !> 3, r = 1. 
// l = 0 , r = 1. mid = 0. nums[0] = 1, 1 !> 2, r = 0
// l == r, return nums[0] ( = 1).

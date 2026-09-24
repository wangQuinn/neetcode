class Solution {
public:
    int trap(vector<int>& height) {
        // seems two pointer-y 
        // you want to find the minimum rectangle each can make with the next one. 
        //stack to keep track of the last one? 
        //at index i, the formula for trapped water is min[height[l], height[r]] - height[i]
        // so now the problem becomes how do we get the greater height[l] and the max height[r]
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());
        if(height.size() ==0) return 0;
        int pre = 0;
        int suf =0;
        for(int i = 0; i < height.size(); i++){
            pre = max(pre, height[i]);
            prefix[i] = pre;
            suf = max(suf, height[height.size()-1 - i]);
            suffix[height.size()-1 - i] = suf;
        }
        // for(int i = height.size()-1; i > -1; i--){
        //     suf= max(suf, height[i]);
        //     suffix[i] = suf;
        // }
        int water =0;
        for(int i = 0; i < height.size(); i++){
            water += min(prefix[i], suffix[i]) - height[i];
        }
        return water;
    }
};

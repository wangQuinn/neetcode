class Solution {
public:
    int maxArea(vector<int>& heights) {
        //want two pointers 
        // one that 
        int maxArea = 0;
        int left = 0;
        int right = heights.size()-1;
        while(left < right){ //checks all the pairs
            int area = min(heights[left], heights[right]) * (right - left);
            maxArea = max(area, maxArea);
            if(heights[left] < heights [right]) left ++;
            else right --;
        }
        return maxArea;
    }
};

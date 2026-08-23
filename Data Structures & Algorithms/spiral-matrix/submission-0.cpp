class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //i can do this naively by keeping 4 trackers of which side i'm on and for loop aggressively like so 
        //i guess that would be O(1) space and like O(m * n)
        //ok lets do it!

        vector<int> result;
        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int down = matrix.size() -1 ;
        
        while(left <= right && top <= down){
            //left
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]); 
            }
            top ++;
            //down 
            for(int j = top; j <= down; j++){
                result.push_back(matrix[j][right]); 
            }
            right--;
            //right
            if(top > down) break;
            for(int x = right; x >= left; x --){
                result.push_back(matrix[down][x]);
            }
            down --;
            //up
            if(left > right) break;
            for(int y = down; y >= top; y--){
                result.push_back(matrix[y][left]);
            }
            left ++;
        }
        return result;
        
    }
};

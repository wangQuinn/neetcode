class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //rmbr dot product a1b1 + a2b2 = 0 means that angel must be 90 degrees, 
        //so transpose of the coordinates and then negate one.
        
        //flip the rows (negate the i) negate first!! 
        for(int i = 0; i < matrix.size()/2; i++){
            vector<int> tempRow = matrix[i];
            matrix[i] = matrix[matrix.size() - 1 - i];
            matrix[matrix.size() - 1 - i] = tempRow;
        }
        
        //transpose
        for(int i = 0 ; i < matrix.size(); i++){
            for(int j = 0; j < i; j++){ // has to only run down the diagonal or else it will flip twice. 
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

       


    }
};

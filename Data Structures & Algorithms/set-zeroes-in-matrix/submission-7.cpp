#include <unordered_map> 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //O(1) space solution. 
        bool rowZerod = false;
        bool colZerod = false;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    if(i ==0 ) rowZerod = true;
                    if(j ==0) colZerod = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            
            }
        }
        for(int i = 1; i < matrix.size();i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(rowZerod)
            for(int i = 0; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        if(colZerod){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
        
        }
};

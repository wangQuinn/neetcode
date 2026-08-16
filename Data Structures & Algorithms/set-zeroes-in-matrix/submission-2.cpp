#include <unordered_map> 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //naiive solution, 
        unordered_map<int, int> zerod_rows;
        unordered_map<int,int> zerod_cols;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    zerod_rows[i] = j;
                    zerod_cols[j] = i;
                }
            }
        }
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(zerod_rows.contains(i) || zerod_cols.contains(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

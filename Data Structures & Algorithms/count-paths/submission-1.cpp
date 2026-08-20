class Solution {
public:
// the naiive solution -> dfs each path, keep a running total 
// then we could memoize this solution
//start from the bottom right
//have an array which keeps the distance from bottom right 
//then explore up and left, number of unique paths, 
//can flip it to start at the top left for easier processing. 

//time complexity : O(m*n) 
//space complexity : O(m*n)

    int uniquePaths(int m, int n) {
        // int numUnique[m][n];
        vector<vector<int>> numUniquePaths(m, vector<int>(n, 0));
    

        for(int i =0; i < m;i++){
            for(int j= 0; j < n; j++){
                if(i== 0 || j ==0){numUniquePaths[i][j] = 1; continue;}
                int squareTotal = 0;
               
                squareTotal += numUniquePaths[i-1][j];
                squareTotal += numUniquePaths[i][j-1];
                
                numUniquePaths[i][j] = squareTotal;
            }
        }
        return numUniquePaths[m-1][n-1];
        
    }
};

#include <queue> 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i= 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    sinkIsland(grid, {i,j});
                    count ++;
                }
            }
        }
        return count;
    }
    
    void sinkIsland(vector<vector<char>>& grid, pair<int,int> initalCoords){
        queue<pair<int, int>> coordsToBeSunk;
        coordsToBeSunk.push(initalCoords);
        while(!coordsToBeSunk.empty()){
            pair<int, int> coords = coordsToBeSunk.front();
            coordsToBeSunk.pop();
            if(coords.first > -1 && coords.first < grid.size() && coords.second > -1 && coords.second < grid[0].size())
            {
                if(grid[coords.first][coords.second] == '0') continue;
                grid[coords.first][coords.second] = '0';
                //add all four directions
                coordsToBeSunk.push({coords.first + 1, coords.second});
                coordsToBeSunk.push({coords.first, coords.second + 1});
                coordsToBeSunk.push({coords.first -1, coords.second});
                coordsToBeSunk.push({coords.first, coords.second - 1});
            }
                
        }

    }
};

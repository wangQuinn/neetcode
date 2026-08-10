#include <queue> 
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxSize = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) maxSize = max(maxSize, sinkIslandBFS(grid, i, j));
            }
        }
        return maxSize;
    }
    int sinkIslandBFS(vector<vector<int>> & grid, int initalX, int initalY){
        queue<pair<int,int>> coords;
        coords.push({initalX, initalY});
        int size = 0;
        while(!coords.empty()){
            int x = coords.front().first;
            int y = coords.front().second;
            coords.pop();
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) continue;
            if(grid[x][y] == 0) continue;

            grid[x][y] = 0;
            coords.push({x + 1,y});
            coords.push({x - 1,y});
            coords.push({x, y + 1});
            coords.push({x, y -1});
            size ++; //valid sqaure
        }
        return size;
    }
};

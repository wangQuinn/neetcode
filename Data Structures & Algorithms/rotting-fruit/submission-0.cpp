#include <queue> 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mins = 0;
        queue<pair<int,int>> toBeRotted;
        //inital flood
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    toBeRotted.push({i,j});
                }
            }
        }
        rotOranges(grid, toBeRotted, mins);
        //check
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(mins == 0) return 0;
        return mins -1;

    }
    void rotOranges(vector<vector<int>> & grid, queue<pair<int,int>>& toBeRotted, int& mins){
        //lets use a bfs! 
        while(!toBeRotted.empty()){
            int levelSize = toBeRotted.size();
            //remove the orange
            while(levelSize > 0){
                int x = toBeRotted.front().first;
                int y = toBeRotted.front().second;
                
                toBeRotted.pop();
                cout <<"x : " << x << "y : " << y << endl;
                
                //add the adjacent oranges 
                int xDir[] = {1,0,-1,0};
                int yDir[] = {0,-1,0,1};
                for(int i = 0; i < 4; i++){
                    cout <<"xc : " << x + xDir[i] << "yc : " << y+yDir[i] << endl;
                    if(x + xDir[i] < grid.size() && y + yDir[i] < grid[0].size()
                    && y + yDir[i] >= 0 && x + xDir[i] >= 0 && grid[x+xDir[i]][y+yDir[i]] == 1){
                        cout <<"added" << endl;
                        grid[x + xDir[i]][y+yDir[i]] = 2;
                        toBeRotted.push({x+xDir[i], y+yDir[i]});
                    }
                }  
                levelSize --;                     
            }
            mins++;
        }
        
    }
};
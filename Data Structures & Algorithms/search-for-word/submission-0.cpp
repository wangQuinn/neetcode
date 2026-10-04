class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //go through and if you find the starting letter, then you call isWordDFS 
        for(int i =0; i < board.size(); i++){
            for(int j =0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && isWord(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }

    bool isWord(vector<vector<char>> & board, string word, int index, int row, int col){
        if(index == word.size()){
            return true; //the word was found
        }
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) 
            return false;
        
        bool temp = false;
        if(board[row][col] == word.at(index)){
            // search the four directions. 
            char placeHolder = board[row][col];
            board[row][col] = '.'; // so it doesn't loop back. 
            temp = 
            isWord(board, word, index + 1, row + 1, col) ||
            isWord(board, word, index + 1, row -1, col) ||
            isWord(board, word, index + 1, row, col + 1) ||
            isWord(board, word, index + 1, row, col - 1);
            board[row][col] = placeHolder;
        }
        return temp;

    }
};

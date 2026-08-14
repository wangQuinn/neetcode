// Time Complexity: 
// let: 
// m = # rows 
// n = # columns 
// L = largest length of the word 
// k = # words 

// O(m * n * 4 * 3^(L-1) + k);

// Space Complexity: 
// worse case: 
// O(k * L)


#include <unordered_map> 
class Node {
    public:
        char val;
        unordered_map<char, Node*> children;
        bool isWord = false;
        int wordIndex;
};
class Trie {
    
    public: 
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word, int index){
        Node* cur = root;
        for(char c : word){
            if(!cur->children.contains(c)){
                Node* newNode = new Node();
                newNode->val = c;
                cur->children[c] = newNode;
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
        cur->wordIndex = index;
    }
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //populating the trie. 
        Trie* trie = new Trie();
        for(int i = 0; i < words.size(); i++) trie->insert(words[i], i);

       vector<string> results;
        for(int i = 0; i < board.size(); i++){
            for(int j =0; j < board[0].size(); j++){
                if(trie->root->children.contains(board[i][j])){
                    dfs(board, trie->root->children[board[i][j]], i, j, results, words);
                }
            }
        } 
        return results;
    }
    
    void dfs(vector<vector<char>>& board, Node * word, int i, int j, vector<string> & results, vector<string> & words){
        if(word->isWord){
            results.push_back(words[word->wordIndex]);
            word->isWord = false; // to prevent duplicates? 
        }
        char temp = board[i][j];
        board[i][j] = '/';
        
        //checking all four directions. 
        if(i + 1 < board.size() && word->children.contains(board[i + 1][j]))
            dfs(board, word->children[board[i+1][j]], i + 1, j, results, words);
        if(i - 1 >= 0 && word->children.contains(board[i - 1][j]))
            dfs(board, word->children[board[i-1][j]], i - 1, j, results, words);
        if(j + 1 < board[0].size() && word->children.contains(board[i][j + 1]))
            dfs(board, word->children[board[i][j + 1]], i, j + 1, results, words);
        if(j - 1 >= 0 && word->children.contains(board[i][j - 1]))
            dfs(board, word->children[board[i][j - 1]], i, j - 1, results, words);
        
        board[i][j] = temp; // restore! backtrcking. 

    }
};



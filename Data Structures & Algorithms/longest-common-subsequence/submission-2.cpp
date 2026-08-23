#include <unordered_map> 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //can't think of an actual tabluation method
        //bashing it is! memoization 
        vector<vector<int>> seenBefore(text1.size(), vector<int>(text2.size(), -1)); //-1 for not seen
        return longestLength(text1, text2, 0, 0, 0, seenBefore);
    }

    int longestLength(string& text1, string& text2, int x, int y, int length, vector<vector<int>> & seenBefore){

        if(x >= text1.size() || y >= text2.size()) return 0;
        if(seenBefore[x][y] != -1){
            return seenBefore[x][y];
        }
        
        if(text1[x] == text2[y]){
            seenBefore[x][y] = 1 + longestLength(text1, text2, x + 1, y+1, length + 1, seenBefore);
            return seenBefore[x][y];
        }
        //doesn't match then: 
        
        int first = longestLength(text1, text2, x + 1, y, length, seenBefore); //advancing the first
        int second = longestLength(text1, text2, x, y +1, length, seenBefore); //advancing the second
        seenBefore[x][y] = max(first, second);
        return seenBefore[x][y];

    }
};

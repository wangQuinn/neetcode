#include <unordered_map> 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> lookUp;
        return helper(s, wordDict, 0, lookUp);
    }
    bool helper(string s, vector<string>& wordDict, int pos,unordered_map<int,bool>& lookUp){
        if(s.size() == pos) return true;
        //try every possible substring, if it doesn't work, then 
        if(lookUp.find(pos) != lookUp.end()) return lookUp[pos]; //O(1) lookup

        for(int i = 0; i < wordDict.size(); i++){
            string keyWord = wordDict[i];
            string subString = s.substr(pos, keyWord.size());
            if(keyWord == subString){
                if(helper(s, wordDict, pos + keyWord.size(), lookUp)){
                    lookUp[pos] = true;
                    return lookUp[pos];
                }
            }
        }
        lookUp[pos] = false;
        return lookUp[pos];
    }
};

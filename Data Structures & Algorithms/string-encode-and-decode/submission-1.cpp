// this is so not the intended
#include <stack> 
class Solution {
public:
    vector<int> starts;
    string encode(vector<string>& strs) {
        starts.clear();
        string encoded = "";
        for(int i = 0; i < strs.size(); i++){
            if(i == 0){
                starts.push_back(strs[i].size());
            }
            else{
                starts.push_back(strs[i].size() + starts[i-1]);
            }
            encoded += strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        if (starts.empty()) return {};
        int previousEnd = 0;
        vector<string> result;
    
        for(int i= 0; (i < starts.size()); i++){
            int currentEnd = starts[i];
            int length = currentEnd - previousEnd;
            result.push_back(s.substr(previousEnd, length));
            previousEnd = currentEnd;

        }
        starts.clear();
        return result;
    }
};

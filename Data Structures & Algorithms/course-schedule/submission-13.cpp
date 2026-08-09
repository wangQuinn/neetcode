#include <unordered_map> 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //only really have to recurs to see if there is a cycle 
        int totalCourses = 0;
        unordered_map<int, int> seenBefore;
        for(int i =0; i < prerequisites.size(); i++){
            if(hasCycle(prerequisites, prerequisites[i][0], seenBefore)) return false;
        }
        return true;
    }

    bool hasCycle(vector<vector<int>> & prereqs, int lookingFor, unordered_map<int, int> & seenBefore){
        if(seenBefore[lookingFor] == 1) return true; // there is a cycle
        if(seenBefore[lookingFor] == 2) return false; //checked alr
        seenBefore[lookingFor] = 1;
        for(int i = 0; i < prereqs.size(); i++){
            if(prereqs[i][1] == lookingFor){
                if(hasCycle(prereqs, prereqs[i][0], seenBefore)) return true;
            }
        }

        seenBefore[lookingFor] = 2; //not a cycle
        return false;
    }
};

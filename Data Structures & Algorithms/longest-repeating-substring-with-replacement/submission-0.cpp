#include <unordered_map>
class Solution {
public:
    int characterReplacement(string s, int k) {  
        int frequency[26] = {0};
        // the least number of replacement is the letter with the fewest counts. 
        //we can keep a count of the most frequent? 
        // and then sliding window for the next, and then keep the max
        int maxSize = 0;
        int left = 0;
        for(int right = 0; right < s.size(); right++){
            frequency[s[right] - 'A'] ++;
            // to get the number of replacements 
            while ((right - left + 1) - mostFrequent(frequency) > k){
                frequency[s[left] - 'A'] --;
                left ++;
            }

            // valid window
            maxSize = max(maxSize, right-left+1);
        }
        return maxSize;

    }
    int mostFrequent(int freq[]){
        int maxF = 0;
        for(int i =0; i < 26; i++){
            if(freq[i] > maxF){
                maxF = max(freq[i], maxF);
                //c = 'A' + i;
            }
            
        }
        return maxF;
    }
};

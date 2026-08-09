class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> numCoins(amount + 1);
        for(int i = 0; i < amount + 1; i++) numCoins[i] = INT_MAX;
        numCoins[0] = 0;
        for(int i = 0; i < amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(numCoins[i] != INT_MAX && coins[j] != INT_MAX && coins[j] + i <= amount)
                    numCoins[coins[j] + i] = min(1 + numCoins[i], numCoins[coins[j] + i]);
            }
        }
        if(numCoins[amount] == INT_MAX) return -1;
        return numCoins[amount];
    }
};

//WHAT HAVE I LEARNT FROM THIS PROBLEM :
// if i'm using ceil, I HAVE TO static_cast<double(x) IT OR ELSE. 
//
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end()); //[1,2,3,4]
        //lowest amount of hours its n, the number of things in piles. 
        //can find the maximum of piles, and the n binary search between 1 and max to find 
        //[1,2,3,4] -> max = 4, eating rate of 4 = 4 hours < 9 hours. 
        // = 1, eating rate of 10 hours > 9 hours. 
        // = 2 eating rate of 6 hours ///1 ,2,3,4
        // = 3 eating rate of 5 hours. //10,6,5,4. //want to find the first one that is < h. 

        int maxPile = 0;
        for(int pile : piles){
            maxPile = max(maxPile, pile);
        }

        //binary search from 1 to maxPile 
        int l = 1;
        int r = maxPile;
        int minAmountOfTime = maxPile;
        while(l <= r){
            int mid = (l + r ) / 2;
            int amountOfTime = 0;
            for(int pile: piles){
                amountOfTime += ceil(static_cast<double> (pile) / mid);
            }
            
            if(amountOfTime <= h){// this means there is a slower eating rate that is possible
                minAmountOfTime = mid;
                r = mid -1;
            }
            else{
                l = mid + 1;
            }


        }
        return minAmountOfTime;

    }
};

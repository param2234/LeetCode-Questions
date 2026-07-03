class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int ans = 0;

        ans += numBottles;
        int count;

       while(numBottles >= numExchange && numBottles !=0){

            count = 0;
             while(numBottles >= numExchange){
                numBottles = numBottles - numExchange;
                count++;
            }

            numBottles += count;
            ans+= count;
       }

       return ans;
    }
};
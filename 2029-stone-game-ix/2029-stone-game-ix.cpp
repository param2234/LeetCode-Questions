class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int c0 = 0, c1 = 0, c2 = 0;

        for (int x : stones) {
            if (x % 3 == 0)
                c0++;
            else if (x % 3 == 1)
                c1++;
            else
                c2++;
        }

        // Number of multiples of 3 is even
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }

        // Number of multiples of 3 is odd
        return abs(c1 - c2) > 2;
    }
};
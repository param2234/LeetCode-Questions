class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        int even = n*(n+1);

        int odd = n*n;

        int div = 1;
        for(int i = 1 ; i <= min(even,odd) ; i++){

            if( even % i == 0 && odd % i == 0)div = i;
        }

        return div;
    }
};
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;

        int temp = n;

        while(temp){
            int dig =  temp % 10;
            temp = temp /10;

            sum += dig;
            prod *= dig;
        }

        if(n % (sum + prod) == 0){
            return true;
        }

        return false;
    }
};
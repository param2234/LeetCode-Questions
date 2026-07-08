class Solution {
public:
    long long sumAndMultiply(int n) {
        long long dig = 0;
        long long sum = 0;
        int scale = 1;

        while(n){
            int num = n % 10;
            n = n/10;

            if(num){
                dig = dig + scale*num; 
                sum += num;
                scale *= 10;
            }
        }

        return 1LL*(dig*sum);
    }
};
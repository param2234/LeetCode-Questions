class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(true){
            int temp = n;
            int prod = 1;
            while(temp){
                int dig = temp % 10;
                temp = temp / 10;

                prod = prod * dig;
            }

            if(prod % t == 0)return n;

            n++;
        }
    }
};
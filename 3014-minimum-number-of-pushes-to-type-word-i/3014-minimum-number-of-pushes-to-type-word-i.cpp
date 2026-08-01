class Solution {
public:
    int minimumPushes(string word) {
        
        int n = word.size();

        if(n <= 8){
            return n;
        }

        int ans = 0;
        int count = 1;

        while(n>0){

            int add = min(n,8);

            ans += add*count;
            n -= add;
            count++;
        }

        return ans;

    }
};
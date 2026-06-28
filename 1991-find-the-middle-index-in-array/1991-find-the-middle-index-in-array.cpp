class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);

        int lsum = 0;
        int rsum = 0;

        for(int i = 1;i<n;i++){
            lsum += nums[i-1];
            leftsum[i] = lsum;
        }

        for(int i = n-2;i>=0;i--){
            rsum += nums[i+1];
            rightsum[i] = rsum;
        }

        for(int i = 0;i<n;i++){
            if(leftsum[i] == rightsum[i])return i;
        }

        return -1;
    }
};
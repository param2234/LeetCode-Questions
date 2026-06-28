class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans(nums.size(),0);


        int lidx = 0;
        int ridx = 0;
        int lsum = 0;
        int rsum = 0;

        for(int i = 0;i<nums.size();i++){
            
            lsum = rsum = 0;
            lidx = ridx = i;

            while(lidx >=0){
                lsum += nums[lidx--];
            }

            while(ridx < nums.size()){
                rsum += nums[ridx++];
            }

            ans[i] = abs(lsum - rsum);

        }

        return ans;
    }
};